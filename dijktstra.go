package main

import (
	"fmt"
	"os"
	"strconv"
	"time"
)

func main() {
	args := os.Args

	if len(args) != 2 {
		println("call: dijkstra <range end number>")
		return
	}

	last, err := strconv.ParseInt(args[1], 10, 32)
	if err != nil {
		println(err)
	}

	started := time.Now()
	primes := *dijkstraPrimes(int(last))

	for _, p := range primes {
		fmt.Printf("%d ", p)
	}

	fmt.Printf("\n%d primes in range [2-%d] found in %d ms \n",
		len(primes), last, time.Since(started).Microseconds())
}

func dijkstraPrimes(last int) *[]int {
	primes := []int{2}
	pool := []int{4}

	for test := 3; test <= last; test++ {
		isPrim := true
		for index := 0; index < len(pool); index++ {
			if pool[index] == test {
				pool[index] += primes[index]
				isPrim = false
			}
		}
		if isPrim {
			primes = append(primes, test)
			pool = append(pool, test*test)
		}
	}
	return &primes
}
