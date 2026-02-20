import java.util.Scanner;

public class IpSplit {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the IP please: ");
        String ip = sc.nextLine();

        if (!ip.matches("^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." +
                "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." +
                "([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\." +
                "([01]?\\d\\d?|2[0-4]\\d|25[0-5])$"))
        {
            System.out.println("Error, Invalid input: IP must be X.X.X.X");
        }
        else
        {
            System.out.println("IP: " + ip);
            String[] ipSplit = ip.split("\\.");

            for (String part : ipSplit)
            {
                System.out.println(part);
            }

        }

    }
}
