import java.util.Random;
import java.util.Scanner;

public class SearchArray
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);  // create an object from the Scanner class
        Random random = new Random();  // create an object from the Random class

        int array[];
        int sizeArr;

        System.out.println("\n========== Max and Min Array ==========\n");
        System.out.print("Please Enter Size of Araay (it must be 0 to 1000): ");

        sizeArr = input.nextInt();

        if(sizeArr <= 0 || sizeArr > 1000)
        {
            System.out.println("You Must Enter Size of the Range (0 to 1000)");
            return;
        }

        array = new int[sizeArr];

        for(int i=0; i<sizeArr; i++)
        {
            array[i]=random.nextInt(101);
        }

        for(int i=0; i<sizeArr; i++)
        {
            System.out.println("Element: " + (i+1) + " is: " + array[i]);
        }

        // Bubble Sort
        for(int i=0; i<sizeArr-1; i++)
        {
            for(int j=0; j<sizeArr-i-1; j++)
            {
                if(array[j] > array[j+1])
                {
                    int temp;
                    temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        }

        System.out.println("\nArray After Sorting:");
        for (int i = 0; i < sizeArr; i++)
        {
            System.out.print(array[i] + " ");
        }
        System.out.println();

        long start = System.nanoTime();

        // Binary Search
        int target;
        System.out.print("Please Enter Target to Search: ");
        target = input.nextInt();

        int left=0;
        int right=sizeArr-1;
        boolean found = false;

        while(left <= right)
        {
            int mid=(left+right)/2;

            if(target > array[mid])
            {
                left=mid+1;
            }
            else if(target < array[mid])
            {
                right=mid-1;
            }
            else
            {
                System.out.println("Target found at index: " + mid);
                found = true;
                break;
            }
        }
        if(!found)
        {
            System.out.println("Target not found");
        }

        long end = System.nanoTime();
        System.out.println("Seconds for search running time: " + (end - start) + " ns");
    }

}