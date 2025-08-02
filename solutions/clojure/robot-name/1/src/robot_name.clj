(ns robot-name)

(def letters (map char (range (int \A) (inc (int \Z)))))

(defn generate-name []
  (str (rand-nth letters) 
       (rand-nth letters)
       (rand-int 10)
       (rand-int 10)
       (rand-int 10)))

(def names (atom #{}))

(def robot-inst (atom {}))

(defn unique-name []
  (loop [name (generate-name)]
    (if (contains? @names name)
      (recur (generate-name))
      (do
        (swap! names conj name)
        name))))

(defn robot []
  (do (swap! robot-inst assoc :name (unique-name))
      @robot-inst))

(defn robot-name [robot]
  (:name @robot-inst))

(defn reset-name [robot]
  (swap! robot-inst assoc :name (unique-name)))
