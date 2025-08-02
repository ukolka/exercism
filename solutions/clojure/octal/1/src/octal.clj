(ns octal)

(defn to-decimal [octal-string]
  (let [octal-digits (reverse 
                      (map 
                       #(- (int %) (int \0)) 
                       (vec octal-string)))
        powers-of-8 (take 
                     (count octal-digits)
                     (iterate #(bit-shift-left % 3) 1))]
    (if
        (some #(or (> % 7) (< % 0)) octal-digits)
      0
      (reduce + (mapv * octal-digits powers-of-8)))))
