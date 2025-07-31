(ns armstrong-numbers)

(defn armstrong? [num]
  (let [zero-code (int \0)
        digits (map #(- (int %) zero-code) (seq (str num)))
        pow (fn [base exp] (last (take exp (iterate (partial * base) base))))
        num-digits (count digits)
        sum-digits (reduce + (map #(pow % num-digits) digits))]
    (= num sum-digits)))

