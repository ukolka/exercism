(ns bob
  (:require [clojure.string :as str]))

(defn response-for [s]
  (let [s (str/trim s)
        letter? #(Character/isLetter %)
        upper-case? #(Character/isUpperCase %)
        letters (filter letter? s)
        yell? (and 
               (seq letters) 
               (every? upper-case? letters))]
    (cond
      (and yell? (str/ends-with? s "?")) "Calm down, I know what I'm doing!"
      yell? "Whoa, chill out!"
      (str/ends-with? s "?") "Sure."
      (str/blank? s) "Fine. Be that way!"
      :else "Whatever.")))
