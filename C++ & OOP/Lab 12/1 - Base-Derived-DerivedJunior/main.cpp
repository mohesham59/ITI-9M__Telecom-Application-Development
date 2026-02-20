#include <iostream>

using namespace std;

class Base
{
private:
    int x;

protected:
    int y;

public:
    Base()
    {
      x=5;
      y=5;
      cout << "Base Default Constructor called\n";
    }

    Base(int a, int b)
    {
        x=a;
        y=b;
        cout << "Base Parameterized Constructor called\n";
    }

    ~Base()
    {
        cout << "Base Destructor called\n";
    }

    void set_x(int num)
    {
        x = num;
    }

    void set_y(int num)
    {
        y = num;
    }
    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }

    virtual int sum()
    {
        return x+y;
    }
};

class Derived: public Base
{
private:
    int z;
public:
    Derived() : Base(5,5)
    {
        z=5;
        cout << "Derived Default Constructor called\n";
    }

    Derived(int num1, int num2, int num3) : Base(num1,num2)
    {
        z=num3;
        cout << "Derived Parameterized Constructor called\n";
    }

    ~Derived()
    {
        cout << "Derived Destructor called\n";
    }
    int get_z()
    {
        return z;
    }
    void set_z(int num)
    {
        z = num;
    }
    int sum() //override
    {
        return (z + Base::sum());
    }
};

class Derived_Junior : public Derived
{
private:
    int m;
public:
    // Default constructor
    Derived_Junior() : Derived(5, 5, 5)
    {
        m = 5;
        cout << "Derived_Junior Default Constructor called\n";
    }

    // Parameterized constructor
    Derived_Junior(int a, int b, int c, int d) : Derived(a, b, c)
    {
        m = d;
        cout << "Derived_Junior Parameterized Constructor called\n";
    }

    // Destructor
    ~Derived_Junior()
    {
        cout << "Derived_Junior Destructor called\n";
    }

    // Setter & Getter
    void set_m(int num) { m = num; }
    int get_m() { return m; }

    // Override sum
    int sum() override
    {
        return Derived::sum() + m;
    }
};
int main()
{
    cout << "=== Testing Base ===" << endl;
    Base b1(10, 20);
    cout << "Base sum: " << b1.sum() << endl;   // 30


    cout << "\n=== Testing Derived ===" << endl;
    Derived d1(10, 20, 30);
    cout << "Derived sum: " << d1.sum() << endl;   // 60


    cout << "\n=== Testing Derived_Junior ===" << endl;
    Derived_Junior dj1(10, 20, 30, 40);
    cout << "Derived_Junior sum: " << dj1.sum() << endl;   // 100



    cout << "\n=== Modification Test ===" << endl;
    dj1.set_m(5);
    cout << "After changing m to 5: " << dj1.sum() << endl; // 10 + 20 + 30 + 5 = 65

    cout << "\n=== Pointer of type Base pointing to Base ===" << endl;
    Base* Ptr = &b1;
    cout << "Base sum: " << Ptr->sum() << endl;

    cout << "\n=== Pointer of type Base pointing to Derived ===" << endl;
    Ptr = &d1;
    cout << "Derived sum: " << Ptr->sum() << endl;

    cout << "\n=== Pointer of type Base pointing to Derived_junior ===" << endl;
    Ptr = &dj1;
    cout << "Derived_Junior sum: " << Ptr->sum() << endl;

    return 0;
}
