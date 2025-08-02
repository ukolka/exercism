(ns allergies)

(def allergy-names [:eggs 
                    :peanuts 
                    :shellfish 
                    :strawberries
                    :tomatoes
                    :chocolate
                    :pollen
                    :cats])

(def allergy-scores (take 
                     (count allergy-names) 
                     (iterate #(bit-shift-left % 1) 1)))

(def allergy-by-score (zipmap allergy-scores allergy-names))

(defn allergies [score]
  (filter 
   (complement nil?)
   (map 
    #(allergy-by-score (bit-and % score)) 
    allergy-scores)))

(defn allergic-to? [score allergen]
  (some #(= allergen %) (allergies score)))
