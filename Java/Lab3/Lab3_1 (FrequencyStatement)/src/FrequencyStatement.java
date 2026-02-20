import java.util.Scanner;

public class FrequencyStatement {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);  // create an object from the Scanner class
        String statement;

        System.out.print("\nPlease Enter the Statement: "); // ITI develops people and ITI house of developers and ITI for people
        statement = input.nextLine();

        String words[] = statement.split(" ");
        System.out.println("\nThe Lenght of words: " + words.length);

        System.out.print("\nEnter the word to count: ");
        String wordEnter = input.nextLine();

        System.out.print("\n=== Equals Method(1) ===");
        int wordCount=0;
        for(int i=0; i < words.length; i++)
        {
            if(words[i].equals(wordEnter))
            {
                wordCount++;
            }
        }
        System.out.println("\nthe count of word (" +wordEnter+ ") is: " + wordCount + "\n");


        System.out.print("\n=== substring Method(2) ===");
        String tempStatement = statement;
        int wordCount2 = 0;
        int index;

        while ((index = tempStatement.indexOf(wordEnter)) != -1)
        {
            wordCount2++;
            tempStatement = tempStatement.substring(index + wordEnter.length());
        }

        System.out.println("\nThe count of word (" + wordEnter + ") is: " + wordCount2 + "\n");
    }

}
