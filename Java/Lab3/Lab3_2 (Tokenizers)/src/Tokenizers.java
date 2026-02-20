import java.util.Scanner;
import java.util.StringTokenizer;

public class Tokenizers
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        System.out.print("\nPlease Enter the Statement: ");
        String statement = input.nextLine();

        String words[] = statement.split(" ");
        System.out.println("\nThe Length of words: " + words.length);

        System.out.print("\nEnter the word to use as delimiter: ");
        String delimiterWord = input.nextLine();

        StringTokenizer str = new StringTokenizer(statement, delimiterWord);

        int tokenIndex = 0;

        while (str.hasMoreTokens())
        {
            String token = str.nextToken();
            System.out.println(token + "\n==================");
            tokenIndex++;
        }

        System.out.println("Number of tokens: " + tokenIndex);
    }
}