def main():
  sentence = raw_input()
  words = sentence.split()
 
  # Sort words by length
  words.sort(lambda x,y: cmp(len(y), len(x)))
  print('Longest word: ' + words[0])
 
  print('Descending Order:')
  for word in words:
      print(word)
 
if __name__ == '__main__':
  main()