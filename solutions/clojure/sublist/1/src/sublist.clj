(ns sublist)

(defn sublist? [super-list sub-list]
  (->> (partition (count sub-list) 1 super-list)
       (map (partial = sub-list))
       (some true?)
       boolean))

(defn classify [list1 list2]
  (let [len1 (count list1)
        len2 (count list2)]
    (cond
      (and (= len1 len2) (= list1 list2)) :equal
      (and (> len1 len2) (sublist? list1 list2)) :superlist
      (and (> len2 len1) (sublist? list2 list1)) :sublist
      :else :unequal)))
