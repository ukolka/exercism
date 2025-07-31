(ns reverse-string)

(defn reverse-string [s]
  (apply 
   str
   (loop [ch (first s)
          s (rest s)
          result '()]
     (if (nil? ch)
       result
       (recur 
        (first s)
        (rest s)
        (cons ch result))))))
