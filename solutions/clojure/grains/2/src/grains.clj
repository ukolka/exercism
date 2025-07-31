(ns grains)

(defn square [n]
  (.shiftLeft (biginteger 1) (dec n)))

(defn total []
  (dec (square 65)))

