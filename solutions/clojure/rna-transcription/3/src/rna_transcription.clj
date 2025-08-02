(ns rna-transcription)

(defn to-rna [dna]
  (let [dna-to-rna {\C \G
                    \G \C
                    \A \U
                    \T \A}
        rna (->> dna
                 (map dna-to-rna)
                 (apply str))]
    (assert (= (count dna) (count rna)))
    rna))
