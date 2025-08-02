.number as $num 
| "\(if .number % 3 == 0 then "Pling" else "" end)\(
  if .number % 5 == 0 then "Plang" else "" end)\(
  if .number % 7 == 0 then "Plong" else "" end)" as $str
| if $str|length > 0 then $str else $num end