(ns run-length-encoding)

(defn encode-repetitions [[char & rst :as chars]]
  (cond->> char
    (seq rst) (str (count chars))))

(defn run-length-encode [plain-text]
  "encodes a string with run-length-encoding"
  (->> (partition-by identity plain-text)
       (map encode-repetitions)
       (apply str)))

(defn decode-repetitions [[_ count char]]
  (cond->> char
    (seq count) (repeat (Integer/parseInt count))))

(defn run-length-decode [cipher-text]
  "decodes a run-length-encoded string"
  (->> (re-seq #"(\d*)([a-zA-Z\s])" cipher-text)
       (mapcat decode-repetitions)
       (apply str)))
