//Package collatzconjecture provides the CollatzConjecture function
package collatzconjecture

import (
	"fmt"
)

//CollatzConjecture accepts an int n,
//divides n by 2 when even,
//multipies n by 3 and adds 1 when odd,
//until n is 1, and returns the number of steps to reach 1
func CollatzConjecture(n int) (int, error) {
	for i := 0; ; i++ {
		if n <= 0 {
			return 0, fmt.Errorf("invalid value %d", n)
		}
		if n == 1 {
			return i, nil
		}
		if n%2 == 0 {
			n = n / 2
		} else {
			n = (3 * n) + 1
		}
	}
}
