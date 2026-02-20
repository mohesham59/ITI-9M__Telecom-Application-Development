public class PrintArgument {
    public static void main (String[] args) {

        if (args.length != 2)
        {
            System.out.println("Error, Invalid Input: You Must Enter Two Argument ^_^");
            return;
        }
        if (!args[0].matches("^[0-9]+$"))
        {
            System.out.println("Error, Invalid Input: You Must Enter Frist Argument Number");
            return;
        }

        int num1 = Integer.parseInt(args[0]);

        for (int i = 0; i < num1; i++)
        {
            System.out.println("Print (" + (i+1) + "): " + args[1]);
        }
    }
}
