(ns robot-name)

(def letters (map char (range (int \A) (inc (int \Z)))))

(defn generate-name []
  (str (rand-nth letters) 
       (rand-nth letters)
       (rand-int 10)
       (rand-int 10)
       (rand-int 10)))

(def names (atom #{}))

(defn unique-name []
  (loop [name (generate-name)]
    (if (contains? @names name)
      (recur (generate-name))
      (do
        (swap! names conj name)
        name))))

(defn robot []
  (atom {:name (unique-name)}))

(defn robot-name [robot]
  (:name @robot))

(defn reset-name [robot]
  (swap! robot assoc :name (unique-name)))
