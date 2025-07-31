(ns spiral-matrix)

(defn spiral
  ([n] (spiral n 1))
  ([n start]
   (case n
     0 '()
     1 [(list start)]
     (let [offset #(+ (dec start) %)
           top-right n
           below-top-left (* 4 (dec top-right))
           bottom-left  (- below-top-left top-right -2)
           bottom-right  (+ top-right top-right -1)
           top (map offset (range 1 (inc top-right)))
           left (map offset (range below-top-left bottom-left -1))
           right (map offset (range (inc top-right) bottom-right))
           bottom (map offset (range bottom-left (dec bottom-right) -1))
           next-start (inc (offset below-top-left))
           sub-spiral (spiral (- n 2) next-start)]
       (concat [top]
               (map #(concat
                      [%1]
                      %2
                      [%3]) left sub-spiral right)
               [bottom])))))
