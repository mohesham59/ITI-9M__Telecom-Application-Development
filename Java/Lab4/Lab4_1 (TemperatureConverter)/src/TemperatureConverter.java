import java.util.Scanner;
import java.util.function.Function;

public class TemperatureConverter implements Function<Float, Float> {

    @Override
    public Float apply(Float celsius) {
        return (celsius * 9/5) + 32;
    }

    public static void main (String[] args) {
        TemperatureConverter converter = new TemperatureConverter();
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the Temperature (Celsius) please: ");
        float tempC = sc.nextInt();

        float tempF = converter.apply(tempC);

        System.out.println(tempC + "°C ==> " + tempF + "°F");

    }
}


