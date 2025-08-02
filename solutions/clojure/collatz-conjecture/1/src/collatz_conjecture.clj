(ns collatz-conjecture)

(defn collatz [num]
  (assert (> num 0))
  (loop [num num
         steps 0]
    (if (= num 1)
      steps
      (recur (if (even? num)
               (bit-shift-right num 1)
               (inc (+ num (bit-shift-left num 1)))) 
             (inc steps)))))
