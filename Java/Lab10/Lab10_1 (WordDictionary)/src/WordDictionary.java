import java.util.*;

public class WordDictionary  {
    public static void main(String[] args) {
        DictionaryOperation dict = new DictionaryOperation();

        // Add words
        dict.addWord("Apple");
        dict.addWord("Ant");
        dict.addWord("Banana");
        dict.addWord("Ball");
        dict.addWord("Cat");
        dict.addWord("Car");

        // Print all letters and words
        System.out.println("--- All Words ---");
        dict.printAll();

        // Print words of a specific letter
        System.out.println("\n--- Words starting with B ---");
        dict.printWordsOfLetter('B');

        System.out.println("\n--- Words starting with Z ---");
        dict.printWordsOfLetter('Z');
    }
}



class DictionaryOperation {
    private Map<Character, List<String>> wordsMap;

    public DictionaryOperation() {
        wordsMap = new HashMap<>();

        // Initialize map for A-Z
        for (char c = 'A'; c <= 'Z'; c++) {
            wordsMap.put(c, new ArrayList<>());
        }
    }

    // -----------------------------
    public void addWord(String word) {
        if (word == null || word.isEmpty())
            return;

        char firstChar = Character.toUpperCase(word.charAt(0));

        // Check if firstChar is a valid alphabet
        if (wordsMap.containsKey(firstChar)) {
            List<String> list = wordsMap.get(firstChar);
            list.add(word);

            // Sort the list after adding
            Collections.sort(list);
        }
    }

    // -----------------------------
    public void printAll() {
        for (char c = 'A'; c <= 'Z'; c++) {
            List<String> list = wordsMap.get(c);
            if (!list.isEmpty()) {
                System.out.println(c + ": " + list);
            }
        }
    }

    // -----------------------------
    public void printWordsOfLetter(char letter) {
        char upper = Character.toUpperCase(letter);
        if (wordsMap.containsKey(upper)) {
            List<String> list = wordsMap.get(upper);
            if (!list.isEmpty()) {
                System.out.println(upper + ": " + list);
            } else {
                System.out.println("No words starting with " + upper);
            }
        } else {
            System.out.println(letter + " is not a valid letter");
        }
    }
}