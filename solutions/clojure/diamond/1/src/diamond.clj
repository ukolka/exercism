(ns diamond)

(def letters (apply vector (map char (range 65 91))))

(defn position [[x y] letter]
  {:x x :y y :letter letter})

(defn diamond [c]
  (let [letters (conj 
                 (->> letters
                      (take-while (partial not= c))
                      reverse)
                 c)
        size (dec (* 2 (count letters)))
        middle (quot size 2)
        field (->> (repeat size \space)
                   (into [])
                   (repeat size)
                   (into []))
        letter-positions (->> (map-indexed
              (fn [idx letter] 
                [(position [(+ middle idx) idx] letter)
                 (position [(- middle idx) idx] letter)
                 (position [(- middle idx) (- size idx 1)] letter)
                 (position [(+ middle idx) (- size idx 1)] letter)])
              letters)
             flatten
             set)]
    (->> (reduce 
          (fn [fd lp] (assoc-in fd [(:x lp) (:y lp)] (:letter lp)))
          field
          letter-positions)
         (map (partial apply str)))))


