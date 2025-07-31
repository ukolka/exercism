(ns pig-latin)

(def rule-1 #"^(a|e|i|o|u|xr|yt)")
(def consonants "p|b|th|d|ch|g|f|v|t|s|z|sh|h|c|m|n|l|r|w|y|k|x|qu|q")
(def rule-2 (re-pattern (str "^(" consonants ")+")))
(def rule-3 (re-pattern (str "^(" consonants ")qu")))
(def rule-4 (re-pattern (str "^(" consonants ")+y|^.y$")))

(def not-y? (partial not= \y))

(defn translate-word [w]
  (let [r1 (re-find rule-1 w)
        r2 (re-find rule-2 w)
        r3 (re-find rule-3 w)
        r4 (re-find rule-4 w)]
    (cond
      r1 (str w "ay")
      r4 (->> (concat (drop-while not-y? w) (take-while not-y? w) "ay")
              (apply str))
      r3 (str (clojure.string/replace w rule-3 "") (first r3) "ay")
      r2 (str (clojure.string/replace w rule-2 "") (first r2) "ay")
      :else w)))

(defn translate [s]
  (->> (clojure.string/split s #"\s")
       (map translate-word)
       (clojure.string/join " ")))
