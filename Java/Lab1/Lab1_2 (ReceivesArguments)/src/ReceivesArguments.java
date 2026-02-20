public class ReceivesArguments {
    public static void main (String[] args) {
        int count = 0;

        for (int i = 0; i < args.length; i++)
        {
            System.out.println("Argument (" + (i+1) + ")" + ": " + args[i] );
            count++;
        }
        System.out.println("Number of Arguments: " + count);
    }
}
