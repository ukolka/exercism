(ns minesweeper)

(def line-separator (System/getProperty "line.separator"))

(def deltas [[-1 -1] [-1 0] [-1 1]
             [ 0 -1]        [ 0 1]
             [ 1 -1] [ 1 0] [ 1 1]])

(defn valid-coord? [n-rows n-cols [x y]]
  (and
   (>= x 0)
   (>= y 0)
   (< x n-rows)
   (< y n-cols)))

(defn surroundings [[x y] n-rows n-cols]
  (->> deltas
       (map (partial map + [x y]))
       (filter (partial valid-coord? n-rows n-cols))))

(defn mine-count [mine-field coord n-rows n-cols]
  (->> (surroundings coord n-rows n-cols)
       (map #(get-in mine-field %))
       (filter (partial = \*))
       count))

(defn draw [s]
  (let [s (clojure.string/split-lines s)
        n-rows (count s)
        n-cols (count (first s))]
    (->> (map-indexed  
          (fn [x row] 
            (map-indexed
             (fn [y tile]
               (if (= tile \space)
                 (let [mc (mine-count s [x y] n-rows n-cols)]
                   (if (> mc 0)
                     (char (+ mc (int \0)))
                     tile))
                 tile))
             row))
          s)
         (map (partial apply str))
         (clojure.string/join line-separator))))
