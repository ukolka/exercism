(ns wordy
  (:require [clojure.string :as str]))

(def operators {"multiplied by" *
                "divided by" /
                "minus" -
                "plus" +})

(defn evaluate [s]
  (when-not (str/starts-with? s "What is ")
    (throw (IllegalArgumentException.)))
  (loop [operators (->> (str/split s #" -?\d+[ ?]?")
                       rest
                       (map #(get operators %)))
        operands (->> (str/split s #"[a-zA-Z ?]+")
                      rest
                      (map #(Integer. %)))
        result (first operands)]
    (when (some nil? operators)
      (throw (IllegalArgumentException.)))
    (if (empty? operators)
      result
      (recur
       (rest operators)
       (rest operands)
       ((first operators) result (second operands))))))
