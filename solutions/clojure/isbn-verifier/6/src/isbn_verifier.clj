(ns isbn-verifier)

(defn isbn? [isbn]
  (let [digits (clojure.string/replace isbn #"-" "")]
    (and (boolean 
          (re-matches #"\d{9}[\dX]" digits))
         (->> digits
              (map #(if (= % \X)
                      10  
                      (Character/digit % 10)))
              (map * (range 10 0 -1))
              (apply +)
              (#(mod % 11))
              zero?))))
