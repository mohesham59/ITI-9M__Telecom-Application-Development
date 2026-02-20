public class GenericInterface {
    public static void main(String args[]) {
        ComplexTest c1 = new ComplexTest(-10.0,-3.0);
        ComplexTest c2 = new ComplexTest(-2.0,-5.0);
        ComplexTest c3 = c1.add(c2);
        ComplexTest c4 = c1.subtract(c2);
        ComplexTest c5 = c1.multiply(c2);
        ComplexTest c6 = c1.divide(c2);

        System.out.println("C3 = C1 + C2 = "+c3.getReal()+"+i"+c3.getImaginary());
        System.out.println("C4 = C1 - C2 = "+c4.getReal()+"+i"+c4.getImaginary());
        System.out.println("C5 = C1 * C2 = "+c5.getReal()+"+i"+c5.getImaginary());
        System.out.println("C6 = C1 / C2 = "+c6.getReal()+"+i"+c6.getImaginary());
    }
}

//------------------------------------
//------------------------------------

interface ComplexOperation<T> {
    T getReal();
    T getImaginary();

    //dataType  methodName(dataType variable);
    ComplexOperation<T> add(ComplexOperation<T> z);
    ComplexOperation<T> subtract(ComplexOperation<T> z);
    ComplexOperation<T> multiply(ComplexOperation<T> z);
    ComplexOperation<T> divide(ComplexOperation<T> z);
}

//------------------------------------
//------------------------------------

class ComplexTest implements ComplexOperation<Double> {
    private Double realpart;
    private Double imaginarypart;

    public ComplexTest(Double realpart, Double imaginarypart) {
        this.realpart = realpart;
        this.imaginarypart = imaginarypart;
    }

    @Override
    public Double getReal() {
        return realpart;
    }

    @Override
    public Double getImaginary() {
        return imaginarypart;
    }

    @Override
    public ComplexTest add(ComplexOperation<Double> z) {
        Double realresult = this.realpart + z.getReal();
        Double imaginaryresult = this.imaginarypart + z.getImaginary();

        return new ComplexTest(realresult, imaginaryresult);
    }


    @Override
    public ComplexTest subtract(ComplexOperation<Double> z) {
        Double realresult = this.realpart - z.getReal();
        Double imaginaryresult = this.imaginarypart - z.getImaginary();

        return new ComplexTest(realresult, imaginaryresult);
    }

    @Override
    public ComplexTest multiply(ComplexOperation<Double> z) {
        Double realresult = this.realpart * z.getReal();
        Double imaginaryresult = this.imaginarypart * z.getImaginary();

        return new ComplexTest(realresult, imaginaryresult);
    }

    @Override
    public ComplexTest divide(ComplexOperation<Double> z) {
        Double realresult = this.realpart / z.getReal();
        Double imaginaryresult = this.imaginarypart / z.getImaginary();

        return new ComplexTest(realresult, imaginaryresult);
    }
}