(ns binary-search)

(defn middle [v]
  (bit-shift-right (count v) 1))

(defn search-for 
  ([needle haystack] (search-for needle haystack 0))
  ([needle haystack offset]
   (let [m (middle haystack)
         v (nth haystack m)]
     (cond 
       (and (= m 0)
            (not= v needle)) (throw (Throwable. "not found"))
       (< needle v) (search-for needle (take m haystack) offset)
       (> needle v) (search-for needle (drop m haystack) (+ offset m))
       (= needle v) (+ offset m)))))
