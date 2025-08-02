(ns queen-attack)

(defn string-to-board [s]
  (let [result 
        (->> (clojure.string/split s #"\n")
             (map #(filter (partial not= \space) %))
             (map-indexed 
              (fn [row row-itm]
                (map-indexed 
                 (fn [col col-itm]
                   [col-itm [row col]])
                 row-itm)))
             (apply concat)
             (filter #(not= \_ (first %)))
             (apply concat)
             (map #(case %
                     \W :w
                     \B :b
                     %)))]
    (if (empty? result)
      {}
      (apply (partial assoc {}) result))))

(def board-size 8)

(defn board-string [board]
  (let [{white :w
         black :b} board]
    (str 
     (->> (map-indexed (fn [row row-itm] 
                         (map-indexed 
                          (fn [col col-itm] 
                            (cond
                              (= white [row col]) \W
                              (= black [row col]) \B
                              :else col-itm))
                          (repeat board-size "_"))) 
                       (range board-size))
          (map (partial clojure.string/join " "))
          (clojure.string/join "\n"))
     "\n")))


(defn can-attack [board]
  (let [{white :w
         black :b} board
        [wx wy] white
        [bx by] black]
    (cond
      (= wx bx) true
      (= wy by) true
      (= (apply + white) (apply + black)) true
      (= (apply - white) (apply - black)) true
      :else false)))
