#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    // Default constructor
    Complex()
    {
        this->real = 0;
        this->img = 0;
        cout << "Default Constructor called\n";
    }

    // Parameterized constructor (one or two arguments)
    Complex(int r, int i)
    {
        this->real = r;
        this->img = i;
        cout << "Parameterized Constructor called\n";
    }

    Complex(int r)
    {
        this->real = r;
        this->img = 0;
        cout << "Parameterized Constructor (one arg) called\n";
    }

    // Copy Constructor
    Complex(const Complex& C)
    {
        this->real = C.real;
        this->img = C.img;
        cout << "Copy Constructor, Copied: ";
        PrintComplex();
    }

    // Setters
    void setReal(int r)
    {
        this->real = r;
    }
    void setImg(int i)
    {
        this->img = i;
    }

    // Getters
    int getReal()
    {
        return this->real;
    }
    int getImg()
    {
        return this->img;
    }

    // Member function to add complex numbers
    Complex AddComplex(Complex C)
    {
        Complex temp;
        temp.real = this->real + C.real;
        temp.img = this->img + C.img;
        return temp;
    }

    // Member function to subtract complex numbers
    Complex SubComplex(Complex C)  //  Add by VALUE
    {
        Complex temp;
        temp.real = this->real - C.real;
        temp.img = this->img - C.img;
        return temp;
    }


    // Print function
    void PrintComplex()
    {
        if (this->img < 0)
            cout << this->real << this->img << "i\n";
        else
            cout << this->real << "+" << this->img << "i\n";
    }

    // Destructor
    ~Complex()
    {
        cout << "Destructor called for ";
        this->PrintComplex();
    }
};

int main()
{
    Complex C1(3,4), C2(5), C3;
    C3 = C1.AddComplex(C2);


    cout << "Result: ";
    C3.PrintComplex();

    return 0;
}





