//This is my submission for the competitive coding challenge: Calculate the longest word in a sentence
import java.util.Scanner;
public class LongestWord {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		System.out.println("Enter a sentence.");
		
		String sentence = reader.nextLine(); //takes the entered sentence and makes it a String
		reader.close();
		
		String words[] = new String[sentence.length()]; //array for the words
		for (int i = 0; i < words.length; i++) {
			words[i] = ""; //initializes all words 
		}
		
		String word = ""; //keep track of current word
		int n = 0;
		
		for (int i = 0; i < sentence.length(); i++) { //turns the sentence into words
			//ends writing the current word if the character here is a space
			if (sentence.charAt(i) == ' ') {
				words[n] = word;
				word = "";
				n++; //prevents overwriting words in the array
				continue;
			}
			
			word += sentence.charAt(i); //adds current character to word
			
			if (i == (sentence.length() - 1)) { //makes the word writing also work for the last word in the sentence
				words[n] = word;
				word = "";
				n++; //prevents overwriting words in the array
			}
			
		}
		
		int length = 0; //stores the length of the word
		int checker = 1; //checks that the array still has words in it
		
		System.out.print("Words in descending order of length: ");
		
		while (checker != 0) { //only runs if the longest word's length isn't 0
			
			for (int i = 0; i < words.length; i++) { //runs through the array until an empty word is found
				
				if (words[i].length() > length) { //runs this code if the word here in the array is longer
					
					length = words[i].length();
					n = i; //using n to keep track of where the longest word is
					
				}
				
			}
			
			System.out.print(words[n] + " "); //prints longest word
			words[n] = ""; //clears the longest word so a new longest can be found
			
			checker = length; //updates the checker
			length = 0; //resets length of longest word
			
		}
		
	}

}