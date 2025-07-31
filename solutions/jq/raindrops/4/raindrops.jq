.number as $n
  | [
      [3, "Pling"],
      [5, "Plang"],
      [7, "Plong"]
    ]
  | map(select($n % .[0] == 0) | .[1])
  | add // $n
