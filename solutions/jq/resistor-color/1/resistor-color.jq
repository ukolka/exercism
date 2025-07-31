[
  "black",
  "brown",
  "red",
  "orange",
  "yellow",
  "green",
  "blue",
  "violet",
  "grey",
  "white"
] as $colors
| .input.color as $color
| if .input.color then ($colors | index($color)) else $colors end 