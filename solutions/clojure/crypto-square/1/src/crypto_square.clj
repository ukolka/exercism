(ns crypto-square)

(defn letter? [c] (Character/isLetter c))
(defn digit? [c] (Character/isDigit c))
(defn not-space? [c] (not= \space c))

(defn normalize-plaintext [s]
  (->> s
       (filter #(or (letter? %) (digit? %)))
       (apply str)
       (clojure.string/lower-case)))

(defn square-size [s]
  (let [length (count s)
        candidate-size (int (Math/sqrt length))
        r (quot length candidate-size)
        c (quot length r)]
    (if (or (< c r) (< (* c r) length)) 
      (inc candidate-size)
      candidate-size)))

(defn plaintext-segments 
  ([s] (plaintext-segments s true))
  ([s trim?]
   (let [s (normalize-plaintext s)
         size (square-size s)]
     (->> 
      (partition size size (repeat \space) s)
      (filter (if trim? not-space? identity))
      (map (fn [chars] (apply str (if trim?
                                      (filter not-space? chars)
                                      chars))))
      (filter seq)))))

(defn ciphertext 
  ([s] (ciphertext s false))
  ([s keep-space?]
   (->> (plaintext-segments s false)
        (apply interleave)
        (filter (if keep-space? identity not-space?))
        (apply str))))

(defn normalize-ciphertext [s]
  (let [s (ciphertext s true)
        c (square-size s)
        r (quot (count s) c)]
    (->> (partition r s)
         (map #(apply str (if (= \space (last %))
                            (butlast %)
                            %)))
         (clojure.string/join " ")))) 

