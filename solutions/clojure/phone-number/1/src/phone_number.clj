(ns phone-number)

(def two-to-nine (set "23456789"))

(defn number [num-string]
  (let [invalid "0000000000"
        result (->> (re-seq #"\d" num-string)
                    reverse
                    (take 11)
                    reverse
                    (apply str))
        result (cond
                 (and (= 11 (count result))
                      (= \1 (first result))) (apply str (rest result))
                 (= 10 (count result)) result
                 :else invalid)
        result (if (and (contains? two-to-nine (first result))
                        (contains? two-to-nine (nth result 3)))
                 result
                 invalid)]
    result))

(defn area-code [num-string]
  (->> (number num-string)
       (take 3)
       (apply str)))

(defn exchange-code [num-string]
  (->> (number num-string)
       (drop 3)
       (take 3)
       (apply str)))

(defn subscriber-number [num-string]
  (->> (number num-string)
       (drop 6)
       (take 4)
       (apply str)))

(defn pretty-print [num-string]
  (str "(" (area-code num-string) ") "
       (exchange-code num-string)
       "-"
       (subscriber-number num-string)))
