import string

userinput = input("Enter string: ").split()

for i in range(len(userinput)):
  userinput[i] = userinput[i].strip(string.punctuation)

userinput.sort(key=len, reverse=True)
print("Longest word: ", userinput[0])
print("Descending order: ")
print(userinput)