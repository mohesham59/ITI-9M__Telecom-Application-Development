#include <iostream>

using namespace std;
class Base
{
private:
    int x;
protected:
    int y;

public:
    // Constructors
    Base();
    Base(int a, int b);

    // Destructor
    ~Base();

    // Setters
    void setX(int value);
    void setY(int value);

    // Getters
    int getX();
    int getY();

    // Member function
    int sum();
};

//--------------------------------------------------
//--------------------------------------------------

class Derived : public Base
{
private:
    int z;

public:
    // Constructors
    Derived();
    Derived(int a, int b, int c);

    // Destructor
    ~Derived();

    // Setter
    void setZ(int value);

    // Getter
    int getZ();

    // Member function
    int sum();
};

//--------------------------------------------------
//--------------------------------------------------

class Derived_Junior : public Derived
{
private:
    int m;

public:
    // Constructors
    Derived_Junior();
    Derived_Junior(int a, int b, int c, int d);

    // Destructor
    ~Derived_Junior();

    // Setter
    void setM(int value);

    // Getter
    int getM();

    // Member function
    int sum();
};

//--------------------------------------------------
//--------------------------------------------------

int main()
{
    cout << "===== TESTING BASE CLASS =====\n";
    Base b1(2, 3);
    cout << "Sum Base: " << b1.sum() << endl;
    cout << "-----------------------------\n";

    cout << "===== TESTING DERIVED CLASS =====\n";
    Derived d1(4, 5, 6);
    cout << "Sum Derived: " << d1.sum() << endl;
    cout << "-----------------------------\n";

    cout << "===== TESTING DERIVED_JUNIOR CLASS =====\n";
    Derived_Junior dj1(7, 8, 9, 10);
    cout << "Sum Derived_Junior: " << dj1.sum() << endl;
    cout << "-----------------------------\n";

    cout << "===== END OF MAIN =====\n";

return 0;
}

//--------------------------------------------------
//--------------------------------------------------

// Default constructor
Base::Base()
{
    x=0;
    y=0;
    cout << "Default Constructor called\n";
}

// Parameterized constructor
Base::Base(int a, int b)
{
    x=a;
    y=b;
    cout << "Parameterized Constructor called\n";
}

// Destructor
Base::~Base()
{
    cout << "Destructor called\n";
}

// Setters
void Base::setX(int value)
{
    x = value;
}
void Base::setY(int value)
{
    y = value;
}

// Getters
int Base::getX()
{
    return x;
}
int Base::getY()
{
    return y;
}

// sum function
int Base::sum()
{
    return x + y;
}

//--------------------------------------------------
//--------------------------------------------------

// Default constructor
Derived::Derived()
{
    z=0;
    cout << "Default Constructor Derived called\n";
}

// Parameterized constructor
Derived::Derived(int a, int b, int c) : Base(a,b)
{
    z=c;
    cout << "Parameterized Constructor Derived called\n";
}

// Destructor
Derived::~Derived()
{
    cout << "Destructor Derived called\n";
}

// Setters
void Derived::setZ(int value)
{
    z = value;
}


// Getters
int Derived::getZ()
{
    return z;
}

// sum function
int Derived::sum()
{
    return getX() + y + z;
}

//--------------------------------------------------
//--------------------------------------------------

// Default constructor
Derived_Junior::Derived_Junior() : Derived() // Calls Derived default constructor
{
    m = 0;
    cout << "Default Constructor Derived_Junior called\n";
}

// Parameterized constructor
Derived_Junior::Derived_Junior(int a, int b, int c, int d) : Derived(a, b, c)
{
    m = d;
    cout << "Parameterized Constructor Derived_Junior called\n";
}

// Destructor
Derived_Junior::~Derived_Junior()
{
    cout << "Destructor Derived_Junior called\n";
}

// Setter
void Derived_Junior::setM(int value)
{
    m = value;
}

// Getter
int Derived_Junior::getM()
{
    return m;
}

// sum function
int Derived_Junior::sum()
{

    return getX() + y + getZ() + m;
}
