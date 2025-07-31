(ns say)

(def num->str {
    1 "one"
    2 "two"
    3 "three"
    4 "four"
    5 "five"
    6 "six"
    7 "seven"
    8 "eight"
    9 "nine"
    10 "ten"
    11 "eleven"
    12 "twelve"
    13 "thirteen"
    14 "fourteen"
    15 "fifteen"
    16 "sixteen"
    17 "seventeen"
    18 "eighteen"
    19 "nineteen"
    20 "twenty"
    30 "thirty"
    40 "forty"
    50 "fifty"
    60 "sixty"
    70 "seventy"
    80 "eighty"
    90 "ninety"})

(defn number-under-100 [num]
  (if (> num 20)
    (str (num->str (* 10 (quot num 10))) \- (num->str (rem num 10)))
    (num->str num)))

(defn number-under-1000 [num]
  (let [hundred (quot num 100)
        tens (rem num 100)]
    (str (if (> hundred 0) 
           (str 
            (number-under-100 hundred)
            " hundred ")
           "")
         (if (> tens 0)
           (number-under-100 tens)
           ""))))

(defn split-number [num]
  {:billion (quot num 1000000000)
   :million (rem (quot num 1000000) 1000)
   :thousand (rem (quot num 1000) 1000)
   :hundred (rem num 1000)})

(defn number [num]
  (when (or (< num 0)
            (> num 999999999999))
    (throw (IllegalArgumentException. "invalid number")))
  (if (zero? num)
    "zero"
    (let [num (split-number num)
          billion (:billion num)
          million (:million num)
          thousand (:thousand num)
          hundred (:hundred num)]
      (clojure.string/trimr (str 
             (if (> billion 0) 
               (str (number-under-1000 billion) " billion ")
               "")
             (if (> million 0)
               (str (number-under-1000 million) " million ")
               "")
             (if (> thousand 0)
               (str (number-under-1000 thousand) " thousand ")
               "")
             (if (> hundred 0)
               (str (number-under-1000 hundred))
               ""))))))
