(ns bob
  (:require [clojure.string :as str]))

(defn response-for [s]
  (let [s (str/trim s)
        last-char (last s)
        letters (apply str (filter #(Character/isLetter %) s))
        non-letters (apply str (filter #(not (Character/isLetter %)) s))
        is-a-yell (and (not (str/blank? letters)) (= (str/upper-case letters) letters))]
    (cond
      (and (= last-char \?)
           is-a-yell) 
      "Calm down, I know what I'm doing!"

      is-a-yell 
      "Whoa, chill out!"

      (= last-char \?) 
      "Sure."

      (and (str/blank? letters)
           (str/blank? non-letters)) 
      "Fine. Be that way!"

      :default "Whatever.")))
