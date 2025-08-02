(ns dominoes)

(defn flat-first [d]
  (first (flatten d)))

(defn flat-last [d]
  (last (flatten d)))

(defn flip [d]
  (if (seqable? (first d) )
    (reverse (map reverse d))
    (reverse d)))

(defn connects? 
  ([d1 d2]
   (= (flat-last d1) (flat-first d2)))
  ([d1 d2 d3]
   (and (connects? d1 d2) (connects? d2 d3))))

(defn connect 
  ([d1 d2]
   (cond
     (and (seqable? (first d1))
          (seqable? (first d2))) (concat d1 d2)
     (seqable? (first d1)) (concat d1 [d2])
     (seqable? (first d2)) (concat [d1] d2)
     :else [d1 d2]))
  ([d1 d2 d3]
   (connect (connect d1 d2) d3)))

(defn connect-if-possible 
  [& ds]
  (when (apply connects? ds)
    (apply connect ds)))

(defn chain-partitions [ds]
  (when (seqable? (first ds))
    (for [idx (range (dec (count ds)))]
      [(take (inc idx) ds) (drop (inc idx) ds)])))

(defn d-double? [d]
  (= (flat-first d) (flat-last d)))

(def not-d-double? (complement d-double?))

(defn connections [d1 d2]
  (filter (complement nil?) 
          (concat [(connect-if-possible d1 d2)
                   (connect-if-possible d2 d1)
                   (when (not-d-double? d2)
                     (connect-if-possible d1 (flip d2)))
                   (when (not-d-double? d2)
                     (connect-if-possible (flip d2) d1))]
                  (let [parts (chain-partitions d1)]
                    (concat 
                     (map (fn [[l r]] 
                            (connect-if-possible l d2 r)) 
                          parts)
                     (when (not-d-double? d2) 
                       (map (fn [[l r]] 
                              (connect-if-possible l (flip d2) r)) 
                            parts)))))))

(defn dominoe-eq? [d1 d2]
  (or (= d1 d2) (= (flip d1) d2)))

(def dominoe-not-eq? (complement dominoe-eq?))

(defn drop-first-match [ds d]
  (concat 
   (take-while (partial dominoe-not-eq? d) ds)
   (rest (drop-while (partial dominoe-not-eq? d) ds))))

(defn build-chain [ds]
  (let [candidate (first ds)
        remaining (rest ds)]
    (if (empty? remaining)
      candidate
      (let [cconns (->> remaining
                       (map (fn [d] 
                              {:conns (connections candidate d)
                               :rest (drop-first-match remaining d)}))
                       (filter #(seq (:conns %))))]
        (->>
         (for [conns cconns]
           (for [conn (:conns conns)]
             (let [rest-dominoes (:rest conns)]
               (if (empty? rest-dominoes)
                 conn
                 (first (build-chain (concat [conn] rest-dominoes)))))))
         (apply concat)
         (filter (complement nil?))
         (filter d-double?))))))

(defn can-chain? [ds]
  (cond
    (empty? ds) true
    (= 1 (count ds)) (d-double? (first ds))
    :else (not (empty? (build-chain ds)))))
