(ns anagram)

(defn anagrams-for [word prospect-list]
  (let [lc clojure.string/lower-case
        lc-sort #(sort (lc %))
        lc-word (lc word)
        lc-sorted-word (lc-sort word)]
    (filter 
     #(and (not= (lc word) (lc %))
           (= lc-sorted-word (lc-sort %))) 
     prospect-list)))


