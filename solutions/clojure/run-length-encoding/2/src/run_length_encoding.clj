(ns run-length-encoding)

(defn count->str [count]
  (str (if (= count 1) nil count)))

(defn run-length-encode [plain-text]
  "encodes a string with run-length-encoding"
  (->> (partition-by identity plain-text)
       (map #(str (count->str (count %)) (first %)))
       (apply str)))

(defn count-str->int [count-str]
  (if-not (clojure.string/blank? count-str)
    (Integer/parseInt count-str)
    1))

(defn run-length-decode [cipher-text]
  "decodes a run-length-encoded string"
  (->> (re-seq #"(\d*)([\w\s])" cipher-text)
       (map (fn [[_ count ch]] (repeat (count-str->int count) ch)))
       (map (partial apply str))
       (apply str)))
