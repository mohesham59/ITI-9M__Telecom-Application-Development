#include <graphics.h>
#include <iostream>
using namespace std;
class Shape
{
protected:
    int ShapColor;   // shared color attribute for all shapes

public:
    // Constructor
    Shape()
    {
        ShapColor = WHITE;
    }

    // Setter
    void setColor(int c)
    {
        ShapColor = c;
    }

    // Getter
    int getColor() const
    {
        return ShapColor;
    }

    // Pure virtual draw
    virtual void Draw() = 0;

    // Destructor
    virtual ~Shape()
    {
        // nothing
    }
};

//////////////////////////////////////////////
//                POINT
//////////////////////////////////////////////
class Point : public Shape
{
private:
    int x, y;

public:

    Point() : x(0), y(0)
    {
        cout << "Point Constructor ParaLess.. called ";
    }

    Point(int X, int Y) : x(X), y(Y)
    {
        cout << "Point Constructor Para.. called ";
    }

    void setX(int X)
    {
        x = X;
    }

    void setY(int Y)
    {
        y = Y;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    // override from Shape
    void Draw() override
    {
        setcolor(ShapColor);       // inherited from Shape
        putpixel(x, y, ShapColor); // draw point using shape color
    }
};

//////////////////////////////////////////////
//                LINE
//////////////////////////////////////////////
class Line : public Shape
{
private:
    Point p1, p2;

public:
    // Default constructor
    Line() : Shape(), p1(), p2()
    {
        ShapColor = WHITE;
        cout << "Line Default Constructor called\n";
    }

    // Parameterized constructor with Points
    Line(Point a, Point b, int c) : Shape(), p1(a), p2(b)
    {
        ShapColor = c; // inherited color
        cout << "Line Parameterized Constructor called\n";
    }

    // Parameterized constructor with coordinates
    Line(int x1, int y1, int x2, int y2, int c) : Shape(), p1(x1, y1), p2(x2, y2)
    {
        ShapColor = c; // inherited color
        cout << "Line Parameterized Constructor with coordinates called\n";
    }

    // Setters
    void setP1(Point a)
    {
        p1 = a;
    }
    void setP2(Point b)
    {
        p2 = b;
    }

    // Getters
    Point getP1()
    {
        return p1;
    }
    Point getP2()
    {
        return p2;
    }

    //override Draw from Shape
    void Draw() //override
    {
        setcolor(ShapColor);
        line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }

    // Destructor
    ~Line()
    {
        cout << "Line Destructor called\n";
    }
};


//////////////////////////////////////////////
//                RECTANGLE
//////////////////////////////////////////////
class Rect : public Shape
{
private:
    Point tl;
    Point br;

public:
    // Default constructor
    Rect() : Shape(), tl(), br()
    {
        ShapColor = WHITE;
        cout << "Rectangle Default Constructor called\n";
    }

    // Parameterized constructor with Points
    Rect(Point topLeft, Point bottomRight, int c) : Shape(), tl(topLeft), br(bottomRight)
    {
        ShapColor = c; // inherited color
        cout << "Rectangle Parameterized Constructor called\n";
    }

    // Parameterized constructor with coordinates
    Rect(int x1, int y1, int x2, int y2, int c) : Shape(), tl(x1, y1), br(x2, y2)
    {
        ShapColor = c; // inherited color
        cout << "Rectangle Parameterized Constructor with coordinates called\n";
    }

    // Setters
    void setTL(Point p)
    {
        tl = p;
    }
    void setBR(Point p)
    {
        br = p;
    }

    // Getters
    Point getTL()
    {
        return tl;
    }
    Point getBR()
    {
        return br;
    }

    //override Draw from Shape
    void Draw()
    {
        setcolor(ShapColor);
        rectangle(tl.getX(), tl.getY(), br.getX(), br.getY());
    }

    // Destructor
    ~Rect()
    {
        cout << "Rectangle Destructor called\n";
    }
};

//////////////////////////////////////////////
//                CIRCLE
//////////////////////////////////////////////
class Circle : public Shape
{
private:
    Point center;
    int radius;

public:

    Circle() : Shape(), center(), radius(0)
    {
        cout << "Circle Constructor ParaLess.. called ";
    }

    Circle(Point c, int r, int col) : Shape(), center(c), radius(r)
    {
        ShapColor = col; // inherited color
        cout << "Circle Constructor Para.. called ";
    }

    void setCenter(Point c)
    {
        center = c;
    }

    void setRadius(int r)
    {
        radius = r;
    }

    Point getCenter()
    {
        return center;
    }

    int getRadius()
    {
        return radius;
    }

    // override from Shape
    void Draw()
    {
        setcolor(ShapColor);
        circle(center.getX(), center.getY(), radius);
    }
};

//////////////////////////////////////////////
//                PICTURE
//////////////////////////////////////////////
/*
class Picture
{
private:
    int cNum, rNum, lNum;
    Circle* pCircle;
    Rect* pRects;
    Line* pLine;

public:
    // Constructors
    Picture() : cNum(0), rNum(0), lNum(0), pCircle(nullptr), pRects(nullptr), pLine(nullptr) {}

    Picture(int cn, int rn, int ln, Circle* pc, Rect* pr, Line* pl)
        : cNum(cn), rNum(rn), lNum(ln), pCircle(pc), pRects(pr), pLine(pl) {}

    // Setters
    void setCircles(int cn, Circle* cArr)
    {
        cNum = cn;
        pCircle = cArr;
    }

    void setRects(int rn, Rect* rArr)
    {
        rNum = rn;
        pRects = rArr;
    }

    void setLines(int ln, Line* lArr)
    {
        lNum = ln;
        pLine = lArr;
    }

    // Draw all shapes
    void paint()
    {
        for(int i = 0; i < cNum; i++)
            pCircle[i].Draw();  // uses the color of each Circle

        for(int i = 0; i < rNum; i++)
            pRects[i].Draw();   // uses the color of each Rect

        for(int i = 0; i < lNum; i++)
            pLine[i].Draw();    // uses the color of each Line
    }
};
*/
//////////////////////////////////////////////
//////////////////////////////////////////////


class Picture
{
private:
    ///Shape* PtrShapes[3];
    Shape** PtrShapes;
    int ShapeNum;
public:
    // Constructors
    Picture()
    {
        ShapeNum=0;
        PtrShapes=NULL;
    }

    Picture(Shape** shptr, int n)
    {
        PtrShapes=shptr;
        ShapeNum=n;
    }

    void setShapes(Shape** sArr, int n)
    {
        PtrShapes  = sArr;
        ShapeNum  = n;
    }

    // Draw all shapes
    void paint()
    {
        for (int i = 0; i < ShapeNum ; i++)
        {
            if (PtrShapes [i] != NULL)
                PtrShapes [i]->Draw();  // polymorphic call
        }
    }

     // Destructor
    ~Picture()
    {
        cout<<"Picture Destructor"<<endl;
    }

};


//////////////////////////////////////////////
//                MAIN
//////////////////////////////////////////////
int main() {

    initwindow(800, 600, "Composition Example");

    Circle cirArr[3] = {
        Circle(Point(50, 50), 50, RED),
        Circle(Point(200, 100), 70, GREEN),
        Circle(Point(320, 50), 30, BLUE)
    };


    Rect recArr[2] = {
        Rect(Point(50, 100), Point(300, 400), YELLOW),
        Rect(Point(200, 100), Point(400, 250), CYAN)
    };

    Line linArr[2] = {
        Line(Point(320, 50), Point(200, 300), MAGENTA),
        Line(Point(40, 100), Point(200, 50), WHITE)
    };


    Shape* shapes[7];  // 3 circles + 2 rects + 2 lines

    for (int i = 0; i < 3; i++)
        shapes[i] = &cirArr[i];
    for (int i = 0; i < 2; i++)
        shapes[3 + i] = &recArr[i];
    for (int i = 0; i < 2; i++)
        shapes[5 + i] = &linArr[i];


    Picture myPic;
    myPic.setShapes(shapes, 7);

    myPic.paint();

    getch();
    closegraph();
    return 0;
}
