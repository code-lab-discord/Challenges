package main

import (
  "fmt"
  "bufio"
  "os"
  "strings"
  "sort"
)

func main() {
  fmt.Println("Enter sentence")
  reader := bufio.NewReader(os.Stdin)

  userInput, _ := reader.ReadString('\n')
  userInput = strings.Replace(userInput, "\n", "", -1)

  words := strings.Split(userInput, " ")
  sort.Slice(words, func (i, j int) bool { return len(words[i]) > len(words[j]) })

  longestWord := fmt.Sprintf("Longest word: %s", words[0])
  fmt.Println(longestWord)

  fmt.Println("All Words: ")
  for _, s := range words {
    fmt.Println(s)
  }
}