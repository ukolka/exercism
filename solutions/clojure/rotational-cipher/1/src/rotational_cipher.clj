(ns rotational-cipher)

(defn make-char-window [start end]
  (let [s (int start)
        e (inc (int end))
        diff (- e s)]
    (->> (range s e)
         cycle
         (take (* 3 diff))
         (map char)
         (apply vector))))

(def lcase (make-char-window \a \z))
(def ucase (make-char-window \A \Z))
(def num-letters 26)

(defn rotate-char [rotate-by c]
  (let [rotate-fn (partial 
                   + 
                   (rem rotate-by num-letters)
                   num-letters)
        idx-lcase (.indexOf lcase c)
        idx-ucase (.indexOf ucase c)]
    (cond
      (<= 0 idx-lcase) (nth lcase (rotate-fn idx-lcase))
      (<= 0 idx-ucase) (nth ucase (rotate-fn idx-ucase))
      :else c)))

(defn rotate [s rotate-by]
  (->> (map (partial rotate-char rotate-by) s)
       (apply str)))
