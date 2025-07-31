(ns isbn-verifier)

(defn isbn-digits [isbn]
  (re-seq #"[\dX]" isbn))

(defn valid-isbn? [isbn]
  (->> isbn
   (isbn-digits)
   (apply str)
   (re-matches #"\d{9}[\dX]")
   (boolean)))

(defn isbn? [isbn]
  (and (valid-isbn? isbn)
       (->> isbn
            (isbn-digits)
            (map #(Character/digit (first %) 10))
            (map * (range 10 0 -1))
            (apply +)
            (#(mod % 11))
            (zero?))))
