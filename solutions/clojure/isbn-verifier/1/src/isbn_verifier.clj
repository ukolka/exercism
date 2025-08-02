(ns isbn-verifier)

(defn isbn? [isbn]
  (def digits "0123456789X")
  (let [isbn-digits (->> (re-seq #"[\dX]" isbn)
                         (map #(clojure.string/index-of 
                                digits 
                                (first %))))
        x-at (.indexOf isbn-digits 10)]
    (and (= 10 (count isbn-digits))
         (or (= x-at 9) (= x-at -1))
         (= 0 ((->> isbn-digits
                    (map * (range 10 0 -1))
                    (reduce +)
                    (partial mod)) 11)))))
