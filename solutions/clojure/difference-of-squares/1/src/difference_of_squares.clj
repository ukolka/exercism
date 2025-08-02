(ns difference-of-squares)

(defn pow [b e] (apply * (repeat e b)))

(defn difference [n] 
  (+ 
   (/ (pow n 4) 4)
   (/ (pow n 3) 6) 
   (/ (pow n 2) -4)
   (/ n -6)))

(defn sum-of-squares [n]
  (+
   (/ (pow n 3) 3)
   (/ (pow n 2) 2)
   (/ n 6)))

(defn square-of-sum [n]
  (pow (* (/ n 2) (inc n)) 2))
