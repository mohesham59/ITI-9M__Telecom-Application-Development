#include <iostream>

using namespace std;
#include <iostream>
using namespace std;

class GeoShape
{
private:
    int dim1, dim2;

public:
    GeoShape();
    GeoShape(int d1, int d2);
    virtual ~GeoShape();

    void setdim1(int d1);
    void setdim2(int d2);

    int getdim1();
    int getdim2();

    virtual int CalcArea() = 0;   // PURE VIRTUAL → ABSTRACT CLASS
};
//--------------------------------------------------
//--------------------------------------------------
class Rectangle : protected GeoShape
{
public:
    Rectangle();
    Rectangle(int len, int wid);
    ~Rectangle();

    int CalcArea();
};
//--------------------------------------------------
//--------------------------------------------------
class Square : protected GeoShape
{
public:
    Square();
    Square(int side);
    ~Square();

    int CalcArea();
};
//--------------------------------------------------
//--------------------------------------------------
class Circle : protected GeoShape
{
public:
    Circle();
    Circle(int radius);
    ~Circle();

    int CalcArea();
};
//--------------------------------------------------
//--------------------------------------------------
class Triangle : protected GeoShape
{
public:
    Triangle();
    Triangle(int base, int height);
    ~Triangle();

    int CalcArea();
};

int main()
{
//    GeoShape g;
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

// ---- GeoShape ----
GeoShape::GeoShape()
{
    dim1 = dim2 = 0;
    cout << "Default GeoShape\n";
}

GeoShape::GeoShape(int d1, int d2)
{
    dim1 = d1;
    dim2 = d2;
    cout << "Param GeoShape\n";
}

GeoShape::~GeoShape()
{
    cout << "Destructor GeoShape\n";
}

void GeoShape::setdim1(int d1)
{
    dim1 = d1;
}
void GeoShape::setdim2(int d2)
{
    dim2 = d2;
}

int GeoShape::getdim1()
{
    return dim1;
}
int GeoShape::getdim2()
{
    return dim2;
}

//--------------------------------------------------
// Rectangle
Rectangle::Rectangle()
{
    cout << "Default Rectangle\n";
}

Rectangle::Rectangle(int len, int wid) : GeoShape(len, wid) {
    cout << "Param Rectangle\n";
}

Rectangle::~Rectangle()
{
    cout << "Destructor Rectangle\n";
}

int Rectangle::CalcArea()
{
    return getdim1() * getdim2();
}

//--------------------------------------------------
// Square
Square::Square()
{
    cout << "Default Square\n";
}

Square::Square(int side) : GeoShape(side, side)
{
    cout << "Param Square\n";
}

Square::~Square()
{
    cout << "Destructor Square\n";
}

int Square::CalcArea()
{
    return getdim1() * getdim1();
}

//--------------------------------------------------
// Circle
Circle::Circle()
{
    cout << "Default Circle\n";
}

Circle::Circle(int radius) : GeoShape(radius, radius)
{
    cout << "Param Circle\n";
}

Circle::~Circle()
{
    cout << "Destructor Circle\n";
}

int Circle::CalcArea()
{
    return 3.14 * getdim1() * getdim1();
}

//--------------------------------------------------
// Triangle
Triangle::Triangle()
{
    cout << "Default Triangle\n";
}

Triangle::Triangle(int base, int height) : GeoShape(base, height)
{
    cout << "Param Triangle\n";
}

Triangle::~Triangle()
{
    cout << "Destructor Triangle\n";
}

int Triangle::CalcArea()
{
    return (getdim1() * getdim2()) / 2;
}
