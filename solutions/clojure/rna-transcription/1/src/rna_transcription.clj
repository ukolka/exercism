(ns rna-transcription)

(defn rna-nuc [dna-nuc]
  (let [dna-to-rna {\C \G
                    \G \C
                    \A \U
                    \T \A}]
    (assert (contains? dna-to-rna dna-nuc))
    (get dna-to-rna dna-nuc)))

(defn to-rna [dna]
  (->> dna
       (map rna-nuc)
       (apply str)))
