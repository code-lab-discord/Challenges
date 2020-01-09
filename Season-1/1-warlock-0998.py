import re

stmt = input('Input: ')

words = re.findall(r'\w+', stmt)

print('Words in descending order: ' + ', '.join(x for x in sorted(words, key=len, reverse=True)))