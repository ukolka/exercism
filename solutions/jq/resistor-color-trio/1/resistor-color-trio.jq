.colors 
| {
    black: 0,
    brown: 1,
    red: 2,
    orange: 3,
    yellow: 4,
    green: 5,
    blue: 6,
    violet: 7,
    grey: 8,
    white: 9
} as $colors
| map($colors[.]) 
| (.[0] * 10 + .[1]) * (.[2]|pow10)
| if . < 1000 then 
{
  value: .,
  unit: "ohms"
}
elif . < 1000000 then
{
  value: (. / 1000),
  unit: "kiloohms"
}
elif . < 1000000000 then
{
  value: (. / 1000000),
  unit: "megaohms"
}
else 
{
  value: (. / 1000000000),
  unit: "gigaohms"
}
end
