(ns bank-account)

(def accounts (ref []))

(defn open-account []
  (dosync
    (alter accounts conj 0)
    (dec (count @accounts))))

(defn close-account [account]
  (dosync 
   (alter accounts assoc account nil)))

(defn get-balance [account]
  (dosync 
   (get @accounts account)))

(defn update-balance [account delta]
  (dosync 
   (let [balance (get-balance account)]
     (alter accounts assoc account (+ balance delta)))))

