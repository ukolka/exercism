(ns armstrong-numbers)

(defn into-digits [num]
  (->> (iterate #(quot % 10) num)
       (take-while (partial < 0))
       (map #(rem % 10))))

(defn pow [base exp]
   (apply * (repeat exp base)))

(defn exp-digits [digits]
  (let [num-digits (count digits)]
    (map #(pow % num-digits) digits)))

(defn armstrong? [num]
  (->> num
       into-digits
       exp-digits
       (apply +)
       (= num)))
