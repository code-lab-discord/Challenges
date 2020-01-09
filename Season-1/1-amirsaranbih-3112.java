String sentence = "Hello, beautiful world. What aa beautifuf day!";
        
        char[] letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        
        String longest = "";
        String word = "";
        
        for (int i = 0, n = sentence.length(); i < n; i++) {
            char letter = sentence.charAt(i);
            boolean isLetter = false;
            
            for (int j = 0, m = letters.length; j < m; j++) {
                if (Character.toLowerCase(sentence.charAt(i)) == letters[j]) {
                    isLetter = true;
                    word += letter;
                    break; 
                }
            }
            
            if (!isLetter) {
                if (word.length() >= longest.length()) {
                    longest = word;
                }
                word = "";
            }
        }
        
        System.out.println(longest);