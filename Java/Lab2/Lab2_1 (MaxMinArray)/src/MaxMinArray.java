import java.util.Scanner;
import java.util.Random;

public class MaxMinArray {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        System.out.print("Enter Size of Array: ");
        int size = sc.nextInt();

        if (size < 0 || size > 1000)
        {
            System.out.println("Error, Invalid Input: The Size of Array Must be (0 to 1000)");
        }

        int[] array = new int[size];

        for (int i = 0; i < size; i++)
        {
            array[i] = random.nextInt(1001);
        }

        System.out.println();
        for (int i = 0; i< size; i++)
        {
            System.out.println("Element (" + (i+1) + "): " + array[i]);
        }

        long start = System.nanoTime();
        int min=0, max=0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] < array[min])
            {
                min = i;
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (array[i] > array[max])
            {
                max = i;
            }
        }

        System.out.println("\nMaximum Element of Array is: " + array[max]);
        System.out.println("Minimum Element of Array is: " + array[min] + "\n");

        long end = System.nanoTime();
        System.out.println("Seconds for search running time: " + (end - start) + " ns");


    }
}
