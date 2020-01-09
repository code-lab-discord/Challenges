def longest(word_lst):
    longest_word = max(word_lst, key=len)
    return longest_word, len(longest_word)
string = input("input sentence: ")
lst = string.split(" ")
print(longest(lst))
print("longest to shortest: " + str(sorted(lst, key=len, reverse=True)))