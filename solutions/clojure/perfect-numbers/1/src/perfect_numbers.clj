(ns perfect-numbers)

(defn factors [n]
  (->> (bit-shift-right n 1)
       inc
       (range 1)
       (filter #(zero? (rem n %)))))

(defn classify [n]
  (if (<= n 0)
    (throw (IllegalArgumentException. "positive numbers only"))
    (let [sum-factors (apply + (factors n))]
      (cond 
        (= sum-factors n) :perfect
        (< sum-factors n) :deficient
        (> sum-factors n) :abundant))))
