(ns proverb)

(defn for-want-of-a-thing-the-thing-was-lost [[thing1 thing2]]
  (list "For want of a " thing1 " the " thing2 " was lost.\n"))

(defn and-all-for-the-want-of-a-thing [thing]
  (if (nil? thing)
    ""
    (str "And all for the want of a " thing ".")))

(first '())

(defn recite [[culprit & _ :as inputs]]
  (str (->> (partition 2 1 inputs)
            (mapcat for-want-of-a-thing-the-thing-was-lost)
            (apply str))
       (and-all-for-the-want-of-a-thing culprit)))
