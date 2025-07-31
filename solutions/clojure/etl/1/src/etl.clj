(ns etl)

(defn transform-values [[points values]]
  (->> (repeat (count values) points)
       (map vector (map clojure.string/lower-case values))
       (apply concat)))

(defn transform [source]
  (->> (map transform-values source)
       (apply concat)
       (apply hash-map)))
