(ns poker)

(def ranks ["2" "3" "4" "5" "6" "7" "8" "9" "10" "J" "Q" "K" "A"])
(def suits [\H \S \D \C])

(defn card [s]
  (let [rank (apply str (butlast s))
        suit (last s)
        weight (inc (.indexOf ranks rank))]
    {:rank rank
     :suit suit
     :weight weight
     :alt-weight (if (= rank "A")
                   0
                   weight)}))

(defn normalize-hand [h]
  (->> (clojure.string/split h #" ")
       (map card)))

(defn group-sizes [h attr]
  (->> h
       (group-by attr)
       (map #(count (second %)))))

(defn largest-group [h attr]
  (apply max (group-sizes h attr)))

(defn largest-weight-diff [h w]
  (->> h
     (sort-by w)
     reverse
     (map w)
     (partition 2 1)
     (map (partial reduce -))
     (apply max)))

(defn flush? [h]
  (= 5 (largest-group h :suit)))

(defn straight? 
  ([h] (straight? h :weight))
  ([h w]
   (= 1 (largest-weight-diff h w))))

(defn straight-flush? 
  ([h] (straight-flush? h :weight))
  ([h w]
   (and (straight? h w)
        (flush? h))))

(defn four-of-a-kind? [h]
  (= 4 (largest-group h :rank)))

(defn full-house? [h]
  (= #{2 3} (set (group-sizes h :rank))))

(defn three-of-a-kind? [h]
  (= #{1 3} (set (group-sizes h :rank))))

(defn two-pair? [h]
  (= [1 2 2] (sort (group-sizes h :rank))))

(defn one-pair? [h]
  (= [1 1 1 2] (sort (group-sizes h :rank))))

(defn n-plet-weight 
  ([h n] (n-plet-weight h n :weight))
  ([h n w]
   (->> h
        (group-by w)
        (map #(vector (first %) (count (second %))))
        (filter #(= n (second %)))
        (map first)
        sort
        reverse)))

(defn hand-score [h]
  (cond
    (straight-flush? h) (concat [8] (n-plet-weight h 1))
    (straight-flush? h :alt-weight) (concat [8] (n-plet-weight h 1 :alt-weight))
    (four-of-a-kind? h) (concat [7] (n-plet-weight h 4) (n-plet-weight h 1))
    (full-house? h) (concat [6] (n-plet-weight h 3) (n-plet-weight h 2))
    (flush? h) (concat [5] (n-plet-weight h 1))
    (straight? h) (concat [4] (n-plet-weight h 1))
    (straight? h :alt-weight) (concat [4] (n-plet-weight h 1 :alt-weight))
    (three-of-a-kind? h) (concat [3] (n-plet-weight h 3) (n-plet-weight h 1))
    (two-pair? h) (concat [2] (n-plet-weight h 2) (n-plet-weight h 1))
    (one-pair? h) (concat [1] (n-plet-weight h 2) (n-plet-weight h 1))
    :else (concat [0] (n-plet-weight h 1))))

(defn compare-scores [s1 s2]
  (let [compare-len (min (count s1) (count s2))]
    (compare 
     (into [] (take compare-len s1))
     (into [] (take compare-len s2)))))

(defn make-hand [h]
  {:hand h
   :score (->> h
                  normalize-hand
                  hand-score)})

(defn best-hands [hands]
  (let [ordered-hands (->> hands
                   (map make-hand)
                   (sort-by :score compare-scores)
                   reverse)
        top-hand-score (:score (first ordered-hands))]
    (->> ordered-hands
         (take-while #(= (:score %) top-hand-score))
         (map :hand))))
