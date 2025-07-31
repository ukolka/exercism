(ns largest-series-product)

(defn char->digit [c]
  (let [d (- (int c) (int \0))]
    (do
      (assert (and (>= d 0) (< d 10)))
      d)))

(defn largest-product [n s]
  (assert (and (>= n 0) (<= n (count s))))
  (let [result (->> s
                    (map char->digit)
                    (partition n 1)
                    (map (partial apply *))
                    seq)]
    (if result
      (apply max result)
      1)))

(largest-product 0 "")
