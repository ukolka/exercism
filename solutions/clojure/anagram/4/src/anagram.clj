(ns anagram)

(defn make-word [word]
  (let [lc (clojure.string/lower-case word)]
    {:word word
     :lower-case lc
     :lower-case-sorted (sort lc)}))

(defn same-word? [w1 w2]
  (= (:lower-case w1) (:lower-case w2)))

(defn permutation? [word candidate]
  (= (:lower-case-sorted word)
     (:lower-case-sorted candidate)))

(defn anagram? [word candidate]
  (and (not (same-word? word candidate))
       (permutation? word candidate)))

(defn anagrams-for [word prospect-list]
  (let [word (make-word word)
        anagram-for? #(anagram? word (make-word %))]
    (filter anagram-for? prospect-list)))


