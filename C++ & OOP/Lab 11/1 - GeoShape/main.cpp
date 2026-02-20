#include <iostream>

using namespace std;
class GeoShape
{
private:
    int dim1, dim2;
public:
    // Constructors
    GeoShape();
    GeoShape(int d1, int d2);

    // Destructor
    ~GeoShape();

    // Setters
    void setdim1(int d1);
    void setdim2(int d2);

    // Getters
    int getdim1();
    int getdim2();

    // Member function
    int CalcArea();
};

//--------------------------------------------------
//--------------------------------------------------
///Rectangle
class Rectangle : protected GeoShape
{
public:
    Rectangle();
    Rectangle(int len, int wed);
    int CalcArea();
    ~Rectangle();
};

//--------------------------------------------------
//--------------------------------------------------
///Square
class Square : protected GeoShape
{
public:
    Square();
    Square(int side);
    int CalcArea();
    ~Square();
};

//--------------------------------------------------
//--------------------------------------------------
///Circle
class Circle  : protected GeoShape
{
public:
    Circle ();
    Circle (int radius);
    int CalcArea();
    ~Circle();
};

//--------------------------------------------------
//--------------------------------------------------
///Triangle
class Triangle  : protected GeoShape
{
public:
    Triangle ();
    Triangle (int base, int height);
    int CalcArea();
    ~Triangle();
};

//--------------------------------------------------
//--------------------------------------------------

int main()
{
    cout << "\n========================================\n";
    cout << "       Rectangle Object Creation\n";
    cout << "========================================\n";
    Rectangle rect(5, 10);
    cout << "Rectangle Area: " << rect.CalcArea() << endl;


    cout << "\n========================================\n";
    cout << "          Square Object Creation\n";
    cout << "========================================\n";
    Square sq(6);
    cout << "Square Area: " << sq.CalcArea() << endl;

    cout << "\n========================================\n";
    cout << "          Circle Object Creation\n";
    cout << "========================================\n";
    Circle cir(7);
    cout << "Circle Area: " << cir.CalcArea() << endl;


    cout << "\n========================================\n";
    cout << "         Triangle Object Creation\n";
    cout << "========================================\n";
    Triangle tri(8, 4);
    cout << "Triangle Area: " << tri.CalcArea() << endl;


    cout << "\n========================================\n";
    cout << "           Objects Destruction\n";
    cout << "========================================\n";

return 0;
}

//--------------------------------------------------
//--------------------------------------------------

/// Default constructor
GeoShape::GeoShape()
{
    dim1=0;
    dim2=0;
    cout << "Default Constructor GeoShape called\n";
}

// Parameterized constructor
GeoShape::GeoShape(int d1, int d2)
{
    dim1=d1;
    dim2=d2;
    cout << "Parameterized Constructor GeoShape called\n";
}

// Destructor
GeoShape::~GeoShape()
{
    cout << "Destructor GeoShape called\n";
}

// Setters
void GeoShape::setdim1(int d1)
{
    dim1 = d1;
}
void GeoShape::setdim2(int d2)
{
    dim2 = d2;
}

// Getters
int GeoShape::getdim1()
{
    return dim1;
}
int GeoShape::getdim2()
{
    return dim2;
}

// CalcArea function
int GeoShape::CalcArea()
{
    return 0;
}

//--------------------------------------------------
//--------------------------------------------------

/// Rectangle
Rectangle::Rectangle() //: GeoShape()
{
    cout << "Default Constructor Rectangle called\n";
}

Rectangle::Rectangle(int len, int wid) : GeoShape(len, wid) //dim1=len , dim2=wid
{
    cout << "Parameterized Constructor Rectangle called\n";
}

int Rectangle::CalcArea()
{
    return getdim1() * getdim2();
}
// Destructor
Rectangle::~Rectangle()
{
    cout << "Destructor Rectangle called\n";
}
//--------------------------------------------------
//--------------------------------------------------

/// Square
Square::Square() //: GeoShape()
{
    cout << "Default Constructor Square called\n";
}

Square::Square(int side) : GeoShape(side, side) // dim1 = dim2 = side
{
    cout << "Parameterized Constructor Square called\n";
}

int Square::CalcArea()
{
    return getdim1() * getdim1();
}
// Square
Square::~Square()
{
    cout << "Destructor Square called\n";
}
//--------------------------------------------------
//--------------------------------------------------

/// Circle
Circle::Circle() //: GeoShape()
{
    cout << "Default Constructor Circle called\n";
}

Circle::Circle(int radius) : GeoShape(radius, radius)  // dim1 = dim2 = radius
{
    cout << "Parameterized Constructor Circle called\n";
}

int Circle::CalcArea()
{
    return 3.14 * getdim1() * getdim1();
}
// Destructor
Circle::~Circle()
{
    cout << "Destructor Circle called\n";
}
//--------------------------------------------------
//--------------------------------------------------

/// Triangle
Triangle::Triangle() //: GeoShape()
{
    cout << "Default Constructor Triangle called\n";
}

Triangle::Triangle(int base, int height) : GeoShape(base, height)  //dim1=base , dim2=hight
{
    cout << "Parameterized Constructor Triangle called\n";
}

int Triangle::CalcArea()
{
    return (getdim1() * getdim2()) / 2;
}
// Destructor
Triangle::~Triangle()
{
    cout << "Destructor Triangle called\n";
}
