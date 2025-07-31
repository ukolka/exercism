(ns rna-transcription)

(defn rna-nuc [dna-nuc]
  (let [dna-to-rna {\C \G
                    \G \C
                    \A \U
                    \T \A}]
    (get dna-to-rna dna-nuc)))

(defn to-rna [dna]
  (let [rna (->> dna
                    (map rna-nuc)
                    (apply str))]
    (assert (= (count dna) (count rna)))
    rna))
