(ns robot-simulator)

(defn robot [coord b]
  {:bearing b
   :coordinates coord})

(def bearings [:north :east :south :west :north])

(defn turn [b succession]
  (->> succession
       (partition 2 1)
       (filter #(= b (first %)))
       first
       second))

(defn turn-right [b]
  (turn b bearings))

(defn right [r]
  (robot (:coordinates r) (turn-right (:bearing r))))

(defn turn-left [b]
  (turn b (reverse bearings)))

(defn left [r]
  (robot (:coordinates r) (turn-left (:bearing r))))

(def displacement {:north {:x  0 :y  1}
                   :east  {:x  1 :y  0}
                   :south {:x  0 :y -1}
                   :west  {:x -1 :y  0}})

(defn advance [rob]
  (let [b (:bearing rob)
        disp (get displacement b)
        rob-coord (:coordinates rob)
        next-coord {:x (+ (:x disp) (:x rob-coord))
                    :y (+ (:y disp) (:y rob-coord))}]
    (robot next-coord b)))

(def commands {\R right
               \L left
               \A advance})

(defn simulate [command-str rob]
  (reduce 
   (fn [r c] ((get commands c) r))
   rob 
   command-str))

