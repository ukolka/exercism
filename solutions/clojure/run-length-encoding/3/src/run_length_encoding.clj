(ns run-length-encoding)

(defn count->str [count]
  (str (when (not= count 1) count)))

(defn encode-repetitions [[char & _ :as chars]]
  (str (count->str (count chars)) char))

(defn run-length-encode [plain-text]
  "encodes a string with run-length-encoding"
  (->> (partition-by identity plain-text)
       (map encode-repetitions)
       (apply str)))

(defn count-str->int [count-str]
  (if-not (clojure.string/blank? count-str)
    (Integer/parseInt count-str)
    1))

(defn decode-repetitions [[_ count char]]
  (->> (repeat (count-str->int count) char)
       (apply str)))

(defn run-length-decode [cipher-text]
  "decodes a run-length-encoded string"
  (->> (re-seq #"(\d*)([a-zA-Z\s])" cipher-text)
       (mapcat decode-repetitions)
       (apply str)))
