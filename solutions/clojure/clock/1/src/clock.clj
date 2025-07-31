(ns clock)

(def minutes-in-a-day 1440)

(defn clock->string [clock]
  (str (format "%02d" (quot clock 60))
       ":"
       (format "%02d" (mod clock 60)))
)

(defn clock [hours minutes]
  (mod (+ (* hours 60) minutes) minutes-in-a-day)
)

(defn add-time [clock time]
  (mod (+ clock time) minutes-in-a-day)
)
