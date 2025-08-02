(ns sieve)

(defn multiples [n stop]
  (set (take-while (partial >= stop) (iterate (partial + n) (+ n n)))))

(defn remove-multiples [n stop candidates]
  (let [not-in-multiples? (partial (complement contains?) (multiples n stop))]
    (filter not-in-multiples? candidates)))

(defn sieve [n]
  (if (> 2 n)
    []
    (loop [candidates (remove-multiples 2 n (range 2 (inc n)))
           result [(first candidates)]]
      (if (<= (count candidates) 1)
        result
        (let [rest-candidates (rest candidates)
              next-prime (first rest-candidates)]
          (recur
           (remove-multiples next-prime n rest-candidates)
           (conj result next-prime)))))))
