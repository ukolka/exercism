.strings as $input
| [
  range(1; $input | length) as $indices
  | $indices
  | "For want of a \($input[. - 1]) the \($input[.]) was lost."
]
| if ($input | length) > 0 then . += ["And all for the want of a \($input[0])."] 
  else . end 
