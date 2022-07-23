package main

import (
	"bufio"
	"fmt"
	"os"
)

func ShellSort() {
	in := bufio.NewReader(os.Stdin)
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		s, _ := in.ReadString('\n')
		fmt.Println(s)
	}
	for i := 0; i < n; i++ {
		s, _ := in.ReadString('\n')
		fmt.Println(s)
	}
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 0; i < T; i++ {
		ShellSort()
	}
}
