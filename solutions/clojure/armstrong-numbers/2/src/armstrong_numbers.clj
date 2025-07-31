(ns armstrong-numbers)

(defn armstrong? [num]
  (let [digits (->> (take-while 
                     (partial < 0) 
                     (iterate #(quot % 10) num))
                    (map #(rem % 10)))
        pow (fn [base exp] (apply * (repeat exp base)))
        num-digits (count digits)
        sum-digits (->> digits
                        (map #(pow % num-digits))
                        (apply +))]
    (= num sum-digits)))




