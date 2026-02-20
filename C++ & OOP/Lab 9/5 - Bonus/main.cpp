#include <iostream>
#include <math.h>
using namespace std;
#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    //constructors
    Complex();
    Complex(int r, int i);
    Complex(int r);
    // Copy Constructor
    Complex(const Complex& C);
    // Setters
    void setReal(int r);
    void setImg(int i);
    // Getters
    int getReal();
    int getImg();
    // Member function
    Complex AddComplex(Complex C);
    Complex SubComplex(Complex C);
    // Print function
    void PrintComplex();
    // Destructor
    ~Complex();

    // Function Operators
    Complex operator-(const Complex& c); // c1 - c2
    Complex operator+(const Complex& c); // c1 + c2
    Complex operator-(int num); // c2 - 7
    Complex& operator-=(Complex& c);  // operator C1-=C2;  c1 = c1 - c2;
    Complex operator--();  // operator C2=--C1;  c1 = c1 - 1;
    Complex operator--(int);  // operator C2=C1--;  c1 = c1 - 1;
    int operator==(Complex& c);  // operator C1 == C2
    int operator!=(Complex& c);  // operator C1 != C2
    double Magntude() const;  //operator sqrt(pow()+pow())
    int operator>(Complex& c);  // operator C1 > C2;
    int operator>=(Complex& c);  // operator C1 >= C2;
    int operator<(Complex& c);  // operator C1 < C2;
    int operator<=(Complex& c);  // operator C1 <= C2;
    operator int();  // operator (int) C1;
    operator [](char ch);  // operator C1['R']

    // Friend functions for stream operators
    friend ostream& operator<<(ostream &out, const Complex &c);
    friend istream& operator>>(istream &in, Complex &c);
};
Complex operator-(int num, Complex& c); // 7 - c2

//--------------------------------------------------
//--------------------------------------------------

int main()
{
    cout << "===== PROGRAM START =====\n";
    Complex C1(6,4), C2(6,4), C3;

    cout << "\n===== PERFORMING OPERATION: C1 - C2 =====\n";
    C3 = C1 - C2;

    cout << "\n===== PERFORMING OPERATION: C1 + C2 =====\n";
    C3 = C1 + C2;

    cout << "\n===== PERFORMING OPERATION: 7 - C2 =====\n";
    C3 = 7 - C2;

    cout << "\n===== PERFORMING OPERATION: C2 - 7 =====\n";
    C3 = C2 - 7;

    cout << "\n===== PERFORMING OPERATION: C1 > C2 =====\n";
    cout<<"Magntude C1: "<<C1.Magntude()<<endl;
    cout<<"Magntude C2: "<<C2.Magntude()<<endl;
    cout<<(C1>C2);

    cout << "\n===== PERFORMING OPERATION: C1 >= C2 =====\n";
    cout<<"Magntude C1: "<<C1.Magntude()<<endl;
    cout<<"Magntude C2: "<<C2.Magntude()<<endl;
    cout<<(C1>=C2);

    cout << "\n===== PERFORMING OPERATION: C1 < C3 =====\n";
    cout<<"Magntude C1: "<<C1.Magntude()<<endl;
    cout<<"Magntude C3: "<<C3.Magntude()<<endl;
    cout<<(C1<C3);

    cout << "\n===== PERFORMING OPERATION: C1 <= C3 =====\n";
    cout<<"Magntude C1: "<<C1.Magntude()<<endl;
    cout<<"Magntude C3: "<<C3.Magntude()<<endl;
    cout<<(C1<=C3);

    cout << "\n===== PERFORMING OPERATION: C1 -= C2 =====\n";
    C1-=C2;

    cout << "\n===== PERFORMING OPERATION: C2=--C1 =====\n";
    C2=--C1;

    cout << "\n===== PERFORMING OPERATION: C2=C1-- =====\n";
    C2 = C1--;

    cout << "\n===== PERFORMING OPERATION: C1==C2 =====\n";
    cout<<(C1 == C2);

    cout << "\n===== PERFORMING OPERATION: C1!=C2 =====\n";
    cout<<(C1 != C2);

    cout << "\n===== PERFORMING OPERATION: (int)C1 =====\n";
    int realPart = (int)C1;
    cout << "Real part of C1: " << realPart << endl;

    cout << "\n===== PERFORMING OPERATION: C1['R'] =====\n";
    cout << "C1['R']: " <<C1['R']<< endl;


    Complex c1(3, 4), c2(1, -2), c3;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    cin >> c3;
    cout << "You entered: " << c3 << endl;
    cout << "\n===== PROGRAM END =====\n";
    return 0;
}

//--------------------------------------------------
//--------------------------------------------------
// Non-member operators for stream
ostream& operator<<(ostream &out, const Complex &c) {
    if(c.img >= 0) out << c.real << " + " << c.img << "i";
    else out << c.real << " - " << -c.img << "i";
    return out;
}

istream& operator>>(istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.img;
    return in;
}
/// Class Functions
// Default constructor
Complex :: Complex()
{
    this->real = 0;
    this->img = 0;
    cout << "Default Constructor called\n";
    cout << "------------------------\n";
}

// Parameterized constructor (one or two arguments)
Complex :: Complex(int r, int i)
{
    this->real = r;
    this->img = i;
    cout << "Parameterized Constructor called\n";
    cout << "------------------------\n";
}

Complex :: Complex(int r)
{
    this->real = r;
    this->img = 0;
    cout << "Parameterized Constructor (one arg) called\n";
    cout << "------------------------\n";

}

// Copy Constructor
Complex :: Complex(const Complex& C)
{
    this->real = C.real;
    this->img = C.img;
    cout << "Copy Constructor, Copied: ";
    PrintComplex();
    cout << "------------------------\n";
}
//--------------------------------------------------
// Setters
void Complex :: setReal(int r)
{
    this->real = r;
}
void Complex :: setImg(int i)
{
    this->img = i;
}
//--------------------------------------------------
// Getters
int Complex :: getReal()
{
    return this->real;
}
int Complex :: getImg()
{
    return this->img;
}
//--------------------------------------------------
// Member function to add complex numbers
/// Complex AddComplex(Complex C=c2)
Complex Complex :: AddComplex(Complex C)
{
    Complex temp;
    temp.real = this->real + C.real;
    temp.img = this->img + C.img;
    return temp;
}

// Member function to subtract complex numbers
Complex Complex :: SubComplex(Complex C)
{
    Complex temp;
    temp.real = this->real - C.real;
    temp.img = this->img - C.img;
    return temp;
}

// Print function
void Complex :: PrintComplex()
{
    if (this->img < 0)
        cout << this->real << this->img << "i\n";
    else
        cout << this->real << "+" << this->img << "i\n";
}
//--------------------------------------------------
// Destructor
Complex :: ~Complex()
{
    cout << "Destructor called for ";
    this->PrintComplex();
    cout << "------------------------\n";
}

//--------------------------------------------------
//--------------------------------------------------

/// Functions Operation
double Complex :: Magntude() const {

    return(sqrt(pow(this->real,2)+pow(this->img,2)));
}
Complex Complex :: operator-(const Complex& c)  // operator - => C3 = C1 - C2;
{
    Complex result;
    result.real=this->real - c.real;
    result.img=this->img - c.img;
    return result;
    cout << "------------------------\n";
}

Complex Complex :: operator+(const Complex& c)  // operator + => C3 = C1 + C2;
{
    Complex result;
    result.real=this->real + c.real;
    result.img=this->img + c.img;
    return result;
    cout << "------------------------\n";
}

Complex operator-(int num, Complex& c)  // operator C3 = 7 - C2;
{
    Complex result;
    result.setReal(num - c.getReal());
    result.setImg(c.getImg());
    return result;
    cout << "------------------------\n";
}

Complex Complex :: operator-(int num)  // operator C3 = c2 - 7;
{
    Complex result;
    result.setReal(this -> real- num);
    result.setImg(this -> img);
    return result;
    cout << "------------------------\n";
}

Complex& Complex :: operator-=(Complex& c)  // operator C1-=C2;  c1 = c1 - c2;
{
    Complex result;
    result.setReal(this -> real - c.real);
    result.setImg(this -> img - c.img);
    //return result;
    return *this;
    cout << "------------------------\n";
}

Complex Complex :: operator--()  // operator C2=--C1;  c1 = c1 - 1;
{
    this -> real--;
    this -> img--;
    return *this;
    cout << "------------------------\n";
}

Complex Complex :: operator--(int)  // operator C2=C1--;
{
    Complex result=*this;
    --this -> real;
    --this -> img;
    return result;
    cout << "------------------------\n";
}

int Complex :: operator==(Complex& c)  // operator C1 == C2
{
    return(this->real==c.real && this->img==c.img);
    cout << "------------------------\n";
}

int Complex :: operator!=(Complex& c)  // operator C1 == C2
{
    return(this->real!=c.real || this->img!=c.img);
    cout << "------------------------\n";
}

int Complex :: operator>(Complex& c)  // operator C1 > C2;
{   (*this).Magntude();
    return((*this).Magntude()>c.Magntude());
    cout << "------------------------\n";
}

int Complex :: operator>=(Complex& c)  // operator C1 > C2;
{   (*this).Magntude();
    return((*this).Magntude()>=c.Magntude());
    cout << "------------------------\n";
}

int Complex :: operator<(Complex& c)  // operator C1 < C2;
{   (*this).Magntude();
    return((*this).Magntude()<c.Magntude());
    cout << "------------------------\n";
}

int Complex :: operator<=(Complex& c)  // operator C1 <= C2;
{   (*this).Magntude();
    return((*this).Magntude()<=c.Magntude());
    cout << "------------------------\n";
}

Complex::operator int()  // operator (int) C1;
{   return(this->real);
    cout << "------------------------\n";
}


Complex::operator [](char ch)  // operator C1['R']
{   if(ch=='R' || ch=='r')
    {
        return this->real;
    }
    else if(ch=='I' || ch=='i')
    {
        return this->img;
    }
    else
        cout<<"";
    cout << "------------------------\n";
}

