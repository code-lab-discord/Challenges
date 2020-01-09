def main():
    sentence = input("Enter a sentence to sort: ")
    
    words = sentence.split()
    words.sort(key=len, reverse=True)

    print(f"Longest word: {words[0]}")
    print("Words in order: ")
    for word in words:
        print(word)


if __name__ == "__main__":
    main()