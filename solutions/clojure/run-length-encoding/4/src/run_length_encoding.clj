(ns run-length-encoding)

(defn encode-repetitions [[char & _ :as chars]]
  (let [reps (count chars)]
    (cond->> char
      (> reps 1) (str reps))))

(defn run-length-encode [plain-text]
  "encodes a string with run-length-encoding"
  (->> (partition-by identity plain-text)
       (map encode-repetitions)
       (apply str)))

(defn decode-repetitions [[_ count char]]
  (-> 
   (cond-> count
     (= "" count) (str \1))
   Integer/parseInt
   (repeat char)))

(defn run-length-decode [cipher-text]
  "decodes a run-length-encoded string"
  (->> (re-seq #"(\d*)([a-zA-Z\s])" cipher-text)
       (mapcat decode-repetitions)
       (apply str)))
