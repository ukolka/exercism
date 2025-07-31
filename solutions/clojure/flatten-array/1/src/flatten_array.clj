(ns flatten-array)

(defn flatten-recur [arr]
  (reduce #(if (seqable? %2)
             (into %1 (flatten-recur %2))
             (conj %1 %2)) [] arr))


(defn flatten [arr]
  (loop [result []
         item (first arr)
         rest-items (rest arr)]
    (cond 
      (empty? rest-items) (if (nil? item)
                            result
                            (conj result item))
      (nil? item) (recur result (first rest-items) (rest rest-items))
      (sequential? item) (let [[to-take remaining] (split-with (complement sequential?) item)
                               to-take (filter (complement nil?) to-take)
                               remaining (if (empty? remaining)
                                           rest-items
                                           (concat remaining rest-items))]
                           (recur (into result to-take)
                                  (first remaining)
                                  (rest remaining)))
      :else (recur 
             (conj result item)
             (first rest-items)
             (rest rest-items)))))
