(ns matching-brackets)

(def opening-brackets [\{ \[ \(])
(def closing-brackets [\} \] \)])

(defn opening? [b]
  (contains? (set opening-brackets) b))

(defn closing? [b]
  (contains? (set closing-brackets) b))

(defn opening-for? [b candidate]
  (= candidate 
     (get (->> 
           (interleave closing-brackets opening-brackets)
           (apply hash-map))
          b)))

(defn valid? [s]
  (empty? 
   (loop [s s
          result []]
     (let [ch (first s)]
       (cond
         (empty? s) result        
         (and (closing? ch)
              (opening-for? 
               ch 
               (peek result))) (recur (rest s) (pop result))
         (or (opening? ch)
             (closing? ch)) (recur (rest s) (conj result ch))
         :else (recur (rest s) result))))))
