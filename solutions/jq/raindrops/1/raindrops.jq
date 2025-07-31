.number | if . % 3 == 0 and . % 5 == 0 and . % 7 == 0 then "PlingPlangPlong"
elif . % 3 == 0 and . % 5 == 0 then "PlingPlang"
elif . % 3 == 0 and . % 7 == 0 then "PlingPlong"
elif . % 5 == 0 and . % 7 == 0 then "PlangPlong"
elif . % 3 == 0 then "Pling"
elif . % 5 == 0 then "Plang"
elif . % 7 == 0 then "Plong" 
else . end