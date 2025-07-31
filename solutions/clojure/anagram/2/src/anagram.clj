(ns anagram)

(defn anagrams-for [word prospect-list]
  (let [lc clojure.string/lower-case
        lc-sort (comp sort lc)
        lc-word (lc word)
        lc-sorted-word (lc-sort word)
        same-word? #(= lc-word (lc %))
        permutation? #(= lc-sorted-word (lc-sort %))
        anagram? #(and (not (same-word? %))
                       (permutation? %))]
    (filter 
     anagram?
     prospect-list)))


