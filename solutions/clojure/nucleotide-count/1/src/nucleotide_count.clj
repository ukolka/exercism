(ns nucleotide-count)

(defn nucleotide-counts [strand]
  (apply hash-map 
         (concat 
          [\A 0 \T 0 \C 0 \G 0]
          (->> (sort strand)
               (partition-by identity)
               (map #(list (first %) (count %)))
               flatten))))

(defn count-of-nucleotide-in-strand [nucleotide strand]
  (let [result (get (nucleotide-counts strand) nucleotide)]
    (assert (not (nil?  result)))
    result))
