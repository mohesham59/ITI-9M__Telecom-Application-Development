import java.util.Scanner;

public class ExceptionCustom {
    public static void main (String[] args) {
        TestNumberChecker tester = new TestNumberChecker();
        tester.runTests();

    }
}

class InvalidNumberException extends Exception {
    public InvalidNumberException(String message) {
        super(message);
    }
}

class Operator {
    public int calculateFactorial (int num) throws InvalidNumberException {
        if (num == 0)
        {
            throw new InvalidNumberException("Factorial of zero is 0");
        }
        if (num < 0)
        {
            throw new InvalidNumberException("Factorial is not defined for negative numbers");
        }

        int result =1;
        for (int i = 1; i <= num; i++)
        {
            result *= i;
        }
        System.out.println("Factorial of " + num + " = " + result);
        return result;
    }

    public float calculateSquareRoot(float num) throws InvalidNumberException {
        if (num == 0)
        {
            throw new InvalidNumberException("Square Root of zero is 0");
        }
        if (num < 0)
        {
            throw new InvalidNumberException("Square Root is not defined for negative numbers");
        }

        float result = num*num;
        System.out.println("Square Root of " + num + " = " + result);
        return result;
    }

    public float calculateDivision (int dividend, int divisor) throws InvalidNumberException {
        if (divisor == 0)
        {
            throw new InvalidNumberException("Division of zero is invalid");
        }
        float result = (float)dividend / divisor;
        System.out.println(dividend + " / " + divisor + " = " + result);
        return result;
    }
}

class TestNumberChecker {
    public void runTests() {
        Operator checker = new Operator();

        try {
            checker.calculateFactorial(5);
        } catch (InvalidNumberException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Test 1 Complete ^_^\n");
        }

        try {
            checker.calculateFactorial(-3);
        } catch (InvalidNumberException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Test 2 Complete ^_^\n");
        }

        try {
            checker.calculateFactorial(0);
        } catch (InvalidNumberException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Test 3 Complete ^_^\n");
        }
        //-----------------------------------------------------------

        try {
            checker.calculateSquareRoot(16);
        } catch (InvalidNumberException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Test 4 completed\n");
        }

        try {
            checker.calculateSquareRoot(-9);
        } catch (InvalidNumberException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Test 5 completed\n");
        }
        //-------------------------------------------------------------

        try {
            checker.calculateDivision(10, 2);
        } catch (InvalidNumberException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Test 6 completed\n");
        }

        try {
            checker.calculateDivision(10, 0);
        } catch (InvalidNumberException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            System.out.println("Test 7 completed\n");
        }

    }
}