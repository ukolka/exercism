(ns word-count)

(defn word-count [s]
  (->> s
   clojure.string/lower-case
   (re-seq #"\b\w+\b")
   frequencies))
