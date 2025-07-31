(ns roman-numerals)

(defn numerals [number] 
  (condp (fn [div num] (> (quot num div) 0)) number
    1000 (str "M" (numerals (- number 1000)))
    900  (str "CM" (numerals (- number 900)))
    500  (str "D" (numerals (- number 500)))
    400  (str "CD" (numerals (- number 400)))
    100  (str "C" (numerals (- number 100)))
    90   (str "XC" (numerals (- number 90)))
    50   (str "L" (numerals (- number 50)))
    40   (str "XL" (numerals (- number 40)))
    10   (str "X" (numerals (- number 10)))
    9    (str "IX" (numerals (- number 9)))
    5    (str "V" (numerals (- number 5)))
    4    (str "IV" (numerals (- number 4)))
    1    (str "I" (numerals (- number 1)))
    "")
)
