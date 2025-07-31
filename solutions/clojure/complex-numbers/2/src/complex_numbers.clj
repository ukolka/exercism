(ns complex-numbers)

(defn real [[a b]]
  a)

(defn imaginary [[a b]]
  b)

(defn sum-squares [[a b]]
  (+ (* a a) (* b b)))

(defn abs [[a b]]
  (Math/sqrt (sum-squares [a b])))

(defn conjugate [[a b]]
  [a (- b)])

(defn add [[a b] [c d]]
  [(+ a c) (+ b d)])

(defn sub [[a b] [c d]]
  (add [a b] [(- c) (- d)]))

(defn mul [[a b] [c d]]
  [(- (* a c) (* b d))
   (+ (* b c) (* a d))])

(defn div [[a b] [c d]]
  (let [[f e] (mul [b a] [c d])
        sumsq (sum-squares [c d])]
    (map unchecked-float [(/ e sumsq) (/ f sumsq)])))
