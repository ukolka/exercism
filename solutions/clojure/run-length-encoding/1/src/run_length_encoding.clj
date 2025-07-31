(ns run-length-encoding)

(defn count->str [count]
  (str (if (= count 1) nil count)))

(defn run-length-encode
  "encodes a string with run-length-encoding"
  ([plain-text] (run-length-encode plain-text ""))
  ([plain-text result]
   (if (> 2 (count plain-text))
     (str result (apply str plain-text))
     (let [first-char (first plain-text)
           eq-first-char? (partial = first-char)
           encoded-str (str (->> plain-text
                                 (take-while eq-first-char?)
                                 count
                                 count->str)
                            first-char)
           rest-text (drop-while eq-first-char? plain-text)]
       (run-length-encode 
        rest-text 
        (str result encoded-str))))))

(def digits (hash-set \0 \1 \2 \3 \4 \5 \6 \7 \8 \9))
(def digit? (partial contains? digits))

(defn count-str->int [count-str]
  (if-not (clojure.string/blank? count-str)
    (Integer/parseInt count-str)
    1))

(defn run-length-decode
  "decodes a run-length-encoded string"
  ([cipher-text] (run-length-decode cipher-text ""))
  ([cipher-text result]
   (if (> 2 (count cipher-text))
     (str result (apply str cipher-text))
     (let [repetitions (->> cipher-text
                            (take-while digit?)
                            (apply str)
                            count-str->int)
           text-without-count (drop-while digit? cipher-text)
           repeated-chars (->> text-without-count
                               first
                               (repeat repetitions)
                               (apply str))
           rest-text (rest text-without-count)]
       (run-length-decode 
        rest-text 
        (str result repeated-chars))))))
