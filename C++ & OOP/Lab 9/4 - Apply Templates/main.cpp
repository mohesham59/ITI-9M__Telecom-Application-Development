#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T* stk;
    int Tos, Size;

public:
    Stack();               // Parameterless constructor
    Stack(int sz);         // Parameterized constructor
    Stack(const Stack& s); // Copy constructor
    ~Stack();              // Destructor

    bool IsFull();
    bool IsEmpty();
    void push(T value);
    T Pop();
    T Peak();
    Stack Reverse();
    void PrintStack();

    template <typename U>
    friend void viewContent(const Stack<U>& s); // friend function
};

//--------------------------------------------------
//--------------------------------------------------

template <typename T>
void Swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
        return;
    }

//--------------------------------------------------
//--------------------------------------------------
template <typename U>
void viewContent(Stack<U> s)
{
    if(s.IsEmpty()) return;
    for (int i = 0 ; i < s.Tos ; i++)
    {
        cout << "\nelement number " << i << " = " << s.stk[i] << endl;
    }
}

//--------------------------------------------------
//--------------------------------------------------

class Complex {
private:
    int real, img;

public:
    // Constructors
    Complex();
    Complex(int x);
    Complex(int x, int y);
    Complex(const Complex &c);

    // Destructor
    ~Complex();

    // Setters & Getters
    void set_real(int x);
    int get_real() const;

    void set_img(int x);
    int get_img() const;

    // Member functions
    void Print() const;

    Complex AddComplex(Complex c1, Complex c2);
    Complex AddComplex(Complex &c1);
    Complex subComplex(Complex c1, Complex c2);
    void PrintComplex(Complex &c);
};

//--------------------------------------------------
//--------------------------------------------------

int main()
{
    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    cout<<"\nComplex1 After Swap: "<<endl;
    C1.Print();
    cout<<"\nComplex2 After Swap: "<<endl;
    C2.Print();

    Stack<int> S;
    S.push(10);
    S.push(20);
    cout<< S.Pop();

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout<< S2.Pop();

    Stack<Complex> S3(4);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.Pop();
    C.Print();
    return 0;
}

//--------------------------------------------------
//--------------------------------------------------

template <typename T>
Stack<T>::Stack()
{
    Tos = 0;
    Size = 5;
    stk = new T[Size];
    cout << "\nParameterless CTOR.....";
}

// Parameterized constructor
template <typename T>
Stack<T>::Stack(int sz)
{
    Tos = 0;
    Size = sz;
    stk = new T[Size];
    cout << "\nParameterized CTOR.....";
}

// Copy constructor
template <typename T>
Stack<T>::Stack(const Stack& s)
{
    Tos = s.Tos;
    Size = s.Size;
    stk = new T[Size];
    for(int i = 0; i < Tos; i++)
        stk[i] = s.stk[i];
    cout << "\nCopy CTOR.....";
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
    delete[] stk;
    cout << "\nDestructor.....";
}

// IsFull
template <typename T>
bool Stack<T>::IsFull()
{
    return Tos == Size;
}

// IsEmpty
template <typename T>
bool Stack<T>::IsEmpty()
{
    return Tos == 0;
}

// push
template <typename T>
void Stack<T>::push(T value)
{
    if(!IsFull())
        stk[Tos++] = value;
    else
        cout << "\nStack is full!!!!!!";
}

// Pop
template <typename T>
T Stack<T>::Pop()
{
    if(!IsEmpty())
        return stk[--Tos];
    else
    {
        cout << "\nStack is empty";
        return T();
    }
}

// Peak
template <typename T>
T Stack<T>::Peak()
{
    if(!IsEmpty())
        return stk[Tos-1];
    cout << "\nStack is empty";
    return T();
}

// Reverse
template <typename T>
Stack<T> Stack<T>::Reverse()
{
    Stack<T> reversed(Tos);
    for(int i = Tos-1; i >= 0; i--)
        reversed.push(stk[i]);
    return reversed;
}

// PrintStack
template <typename T>
void Stack<T>::PrintStack()
{
    for(int i = 0; i < Tos; i++)
        cout << "\nelement number " << i+1 << " is = " << stk[i];
}

// =================== Friend function ===================
template <typename T>
void viewContent(const Stack<T>& s)
{
    if(s.IsEmpty()) return;
    for(int i = 0; i < s.Tos; i++)
        cout << "element[" << i << "] = " << s.stk[i] << endl;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//--------------------------------------------------
// Constructors
Complex::Complex() : real(0), img(0) {
    cout << "default CTOR" << endl;
}

Complex::Complex(int x) : real(x), img(0) {
    cout << "single parameter CTOR" << endl;
}

Complex::Complex(int x, int y) : real(x), img(y) {
    cout << "parameterized CTOR" << endl;
}

Complex::Complex(const Complex &c) : real(c.real), img(c.img) {
    cout << "copy CTOR....." << endl;
}

// Destructor
Complex::~Complex() {
    cout << "destructing....." << endl;
}

// Setters & Getters
void Complex::set_real(int x) { this->real = x; }
int Complex::get_real() const { return this->real; }

void Complex::set_img(int x) { this->img = x; }
int Complex::get_img() const { return this->img; }

// Print
void Complex::Print() const {
    if(img >= 0) cout << real << " + " << img << "i" << endl;
    else cout << real << " - " << -img << "i" << endl;
}

// Operations
Complex Complex::AddComplex(Complex c1, Complex c2) {
    Complex result;
    result.set_real(c1.get_real() + c2.get_real());
    result.set_img(c1.get_img() + c2.get_img());
    return result;
}

Complex Complex::AddComplex(Complex &c1) {
    this->set_real(this->get_real() + c1.get_real());
    this->set_img(this->get_img() + c1.get_img());
    return *this;
}

Complex Complex::subComplex(Complex c1, Complex c2) {
    Complex result;
    result.set_real(c1.get_real() - c2.get_real());
    result.set_img(c1.get_img() - c2.get_img());
    return result;
}

void Complex::PrintComplex(Complex &c1) {
    if(c1.get_img() > 0)
        cout << c1.get_real() << " + " << c1.get_img() << "i" << endl;
    else
        cout << c1.get_real() << c1.get_img() << "i" << endl;
}
