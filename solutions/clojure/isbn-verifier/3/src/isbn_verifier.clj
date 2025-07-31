(ns isbn-verifier)

(def digits "0123456789X")

(defn isbn? [isbn]
  (let [char-digits (re-seq #"[\dX]" isbn)
        valid-isbn? (->> char-digits
                         (apply str)
                         (re-matches #"\d{9}[\dX]")
                         (boolean))
        int-digits (->> char-digits
                        (map #(clojure.string/index-of 
                               digits 
                               (first %))))]
    (and valid-isbn?
         (zero? (mod 
                 (->> int-digits
                      (map * (range 10 0 -1))
                      (apply +))
                 11)))))
