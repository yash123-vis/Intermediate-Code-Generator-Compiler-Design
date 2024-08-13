package main

import "fmt"

func main() {
	var sum int = 0
	var i int
	var b int
	b = 10*6 + 5
	//Loop Statement
	for i = 0; i < 10; i++ {
		sum++
	}
	fmt.Println("hello")
	var a int = 2
	var F string = "Hello"
	if 7 == 0 {
		fmt.Println("7 is even")
	} else {
		fmt.Println("7 is odd")
	}
	//If statement
	if 8 >= 0 {
		fmt.Println("8 is divisible by 4")
	}
	var num int = 9
	//If - elseif - else statement
	if num < 0 {
		fmt.Println("is negative")
	} else if num < 10 {
		fmt.Println("has 1 digit")
	} else {
		fmt.Println("has multiple digits")
	}
}
