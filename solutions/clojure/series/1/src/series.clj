(ns series)

(defn slices [string length]
  (if (< length 1)
    [""]
    (->> (partition length 1 string)
         (map (partial apply str)))))
