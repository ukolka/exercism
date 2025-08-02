(ns meetup
  (:import java.util.Calendar))

(def days-of-the-week {Calendar/SUNDAY :sunday
                       Calendar/MONDAY :monday
                       Calendar/TUESDAY :tuesday
                       Calendar/WEDNESDAY :wednesday
                       Calendar/THURSDAY :thursday
                       Calendar/FRIDAY :friday
                       Calendar/SATURDAY :saturday})

(defn year [date]
  (. date get Calendar/YEAR))

(defn month [date]
  (. date get Calendar/MONTH))

(defn day-of-the-week [date]
  (days-of-the-week (. date get Calendar/DAY_OF_WEEK)))

(defn day-of-the-month [date]
  (. date get Calendar/DAY_OF_MONTH))

(defn first-of-month [month year]
  (doto
      (. Calendar getInstance)
    (.set year month 1)))

(defn add-days [date days]
  (let [date (. date clone)]
    (doto date
      (.add Calendar/DATE days))))

(defn add-months [date months]
  (let [date (. date clone)]
    (doto date
      (.add Calendar/MONTH months))))

(defn date-cmp [date1 date2]
  (. date1 compareTo date2))

(defn before? [date1 date2]
  (< (date-cmp date1 date2) 0))

(defn make-day [date]
  {:year (year date)
   :month (month date)
   :day (day-of-the-month date)
   :day-of-the-week (day-of-the-week date)})

(defn month-days [month year]
  (let [current (first-of-month month year)
        last (add-months current 1)]
    (loop [current current
           result []]
      (if (before? current last)
        (recur
         (add-days current 1)
         (conj result (make-day current)))
        result))))

(defn meetup [month year day-of-the-week descriptor]
  (let [days (filter
              #(= day-of-the-week (:day-of-the-week %)) 
              (month-days (dec month) year))
        teenth-days (filter 
                     #(and (< 12 (:day %)) (> 20 (:day %))) 
                     days)
        match-teenth (fn [match-day]
                       (first (filter 
                               #(= (:day-of-the-week %) match-day)
                               teenth-days)))
        result (case descriptor
          :last (last days)
          :first (first days)
          :second (second days)
          :third (nth days 2)
          :fourth (nth days 3)
          :fifth (nth days 4)
          :teenth (match-teenth day-of-the-week))]
    [(:year result) (inc (:month result)) (:day result)]))


