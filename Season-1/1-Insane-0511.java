using System;

namespace Challenge_LongestWord
{
    class Program
    {
        static void Main(string[] args)
        {
            //Accept input and create word list
            string sentence = promptInput("Please enter a sentence");
            string[] sortedSentence = sortWords(sentence);

            //Print sorted word list to end user
            foreach (string word in sortedSentence)
            {
                Console.Write($"{word} \t length: {word.Length}\n");
            }
        }

        //A function to prompt for an input and return the input value
        static string promptInput(string prompt)
        {
            Console.WriteLine(prompt);
            return Console.ReadLine();
        }

        //A function that accepts a string input, and returns it as an array thats been sorted
        static string[] sortWords(string phrase)
        {
            char[] seperators = { ' ', ',' };
            string[] arrSentence = phrase.Split(seperators);
            Array.Sort(arrSentence, (x, y) => x.Length.CompareTo(y.Length));
            Array.Reverse(arrSentence);
            return arrSentence;

        }
    }
}