(ns luhn)

(defn to-digit [c]
  (let [zero (int \0)]
    (- (int c) zero)))

(defn double-digit [digit]
  (let [result (* 2 digit)]
    (if (> result 9)
      (- result 9)
      result)))

(defn divisible-by-10 [n]
  (= 0 (rem n 10)))

(defn valid? [s]
  (let [digits (->> s
                (filter (partial not= \space))
                (map to-digit))]
    (if (> 2 (count digits))
      false
      (->> digits
           reverse
           (partition 2)
           (map #(list (first %) (double-digit (second %))))
           flatten
           (apply +)
           divisible-by-10))))
