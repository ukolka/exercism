# You might want to look at:
#
# - the alternative operator:
#   https://jqlang.github.io/jq/manual/v1.7/#alternative-operator
#
# - string interpolation:
#   https://jqlang.github.io/jq/manual/v1.7/#string-interpolation

def name: .name // "you";

"One for \(.|name), one for me."
