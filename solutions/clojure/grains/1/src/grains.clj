(ns grains)

(defn square [n]
  (.shiftLeft (biginteger 1) (dec n)))

(defn total []
  (apply + (map square (range 1 65))))

