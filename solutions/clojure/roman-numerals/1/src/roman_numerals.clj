(ns roman-numerals)


(defn numerals [number] 
  (cond
    (> (quot number 1000) 0) (str "M" (numerals (- number 1000)))
    (> (quot number 900) 0) (str "CM" (numerals (- number 900)))
    (> (quot number 500) 0) (str "D" (numerals (- number 500)))
    (> (quot number 400) 0) (str "CD" (numerals (- number 400)))
    (> (quot number 100) 0) (str "C" (numerals (- number 100)))
    (> (quot number 90) 0) (str "XC" (numerals (- number 90)))
    (> (quot number 50) 0) (str "L" (numerals (- number 50)))
    (> (quot number 40) 0) (str "XL" (numerals (- number 40)))
    (> (quot number 10) 0) (str "X" (numerals (- number 10)))
    (> (quot number 9) 0) (str "IX" (numerals (- number 9)))
    (> (quot number 5) 0) (str "V" (numerals (- number 5)))
    (> (quot number 4) 0) (str "IV" (numerals (- number 4)))
    (> (quot number 1) 0) (str "I" (numerals (- number 1)))
    :else "")
)
