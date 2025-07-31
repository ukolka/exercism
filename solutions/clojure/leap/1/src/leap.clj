(ns leap)

(defn rem-0? [num div]
  (= (rem num div) 0))

(defn leap-year? [year]
  (or (rem-0? year 400)
      (and (not (rem-0? year 100))
           (rem-0? year 4))))
