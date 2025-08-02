(ns go-counting
  (:require [clojure.set]))

(defn is-valid? [grid [x y]]
  (cond 
    (< x 0) false
    (< y 0) false
    (>= x (count (first grid))) false
    (>= y (count grid)) false
    :default true))

(defn up [x y]
  [x (dec y)])

(defn right [x y]
  [(inc x) y])

(defn down [x y]
  [x (inc y)])

(defn left [x y]
  [(dec x) y])

(defn possible-moves [grid [x y]]
  (filter #(is-valid? grid %) [(up x y) (right x y) (down x y) (left x y)]))

(defn get-value [grid [x y]]
  (when (is-valid? grid [x y])
    (get (get grid y) x)))

(defn space? [grid [x y]]
  (= \space (get-value grid [x y])))

(defn black? [grid [x y]]
  (= \B (get-value grid [x y])))

(defn white? [grid [x y]]
  (= \W (get-value grid [x y])))

(defn is-player [grid [x y]]
  (some true? (map #(% grid [x y]) [black? white?])))


(defn explore-territory 
  ([grid [x y]] (explore-territory grid [x y] #{}))
  ([grid [x y] visited]
   (let [explore-territory-recur 
         (fn [] (let [moves (possible-moves grid [x y])]
                 (reduce 
                  clojure.set/union
                  (map #(explore-territory 
                         grid 
                         % 
                         (conj visited [x y])) moves))))]
     (cond
       (contains? visited [x y]) visited
       (not (is-valid? grid [x y])) visited
       (is-player grid [x y]) (conj visited [x y])
       (space? grid [x y]) (conj (explore-territory-recur) [x y])
       :default visited))))

(defn territory [grid [x y]]
  (cond
    (not (is-valid? grid [x y])) (throw (Exception. "Out of bounds"))
    (not (space? grid [x y])) {:owner nil :stones #{}}
    :default (let [explored (explore-territory grid [x y])
                   num-white (count (filter #(white? grid %) explored))
                   num-black (count (filter #(black? grid %) explored))
                   spaces (set  (filter #(space? grid %) explored))]
      (cond
        (and (< 0 num-white) (= 0 num-black)) {:owner :white :stones spaces}
        (and (< 0 num-black) (= 0 num-white)) {:owner :black :stones spaces}
        :default {:owner nil :stones spaces}))))

(defn territories-list [grid]
  (let [xs (range (count (first grid)))
        ys (range (count grid))
        spaces (set (filter #(space? grid %) (for [x xs
                                                   y ys]
                                               [x y])))]
    (loop [current (first spaces)
           current-territory (territory grid current)
           remaining (clojure.set/difference (disj spaces current) (:stones current-territory))
           result [current-territory]]
      (if (empty? remaining)
        result
        (let [current (first remaining)
              current-territory (territory grid current)]
          (recur 
           current
           current-territory
           (clojure.set/difference (disj remaining current) (:stones current-territory))
           (conj result current-territory)))))))


(defn territories [grid]
  (let [update-territory (fn [owner terr acc]
                           (if (= owner (:owner terr))
                             (clojure.set/union acc (:stones terr))
                             acc))]
    (loop [terr-list (territories-list grid)
           result {:black-territory #{}
                   :white-territory #{}
                   :null-territory #{}}]
      (if (empty? terr-list)
        result
        (let [current-territory (first terr-list)
              black-territory (:black-territory result)
              white-territory (:white-territory result)
              null-territory (:null-territory result)]
          (recur
           (rest terr-list)
           {:black-territory (update-territory :black current-territory black-territory)
            :white-territory (update-territory :white current-territory white-territory)
            :null-territory (update-territory nil current-territory null-territory)}))))))
