(ns isbn-verifier)

(def digits "0123456789X")

(defn isbn? [isbn]
  (let [char-digits (re-seq #"[\dX]" isbn)
        int-digits (->> char-digits
                        (map #(clojure.string/index-of 
                               digits 
                               (first %))))]
    (and (->> char-digits
              (apply str)
              (re-matches #"\d{9}[\dX]")
              (boolean))
         (= 0 (mod 
               (->> int-digits
                    (map * (range 10 0 -1))
                    (apply +))
               11)))))
