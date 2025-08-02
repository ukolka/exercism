(ns grade-school)

(defn grade [school grade]
  (get school grade []))

(defn add [school name gr]
  (assoc school gr
         (conj (grade school gr) name)))

(defn sorted [school]
  (->> school
   (map (fn [[key val]] [key (sort val)]))
   (into (sorted-map))))
