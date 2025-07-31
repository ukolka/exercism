.strand 
| split("")
| length as $len
| reduce .[] as $x ({"A": 0, "C": 0, "G": 0, "T": 0}; if (. | has($x)) then .[$x] += 1 else . end)
| if .["A"] + .["C"] + .["G"] + .["T"] == $len then . else ("Invalid nucleotide in strand" | halt_error) end 
