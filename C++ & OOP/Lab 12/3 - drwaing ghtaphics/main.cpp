#include <graphics.h>
#include <iostream>
using namespace std;

//////////////////////////////////////////////
//                POINT
//////////////////////////////////////////////
class Point
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
    void Draw()
    {
        putpixel(x, y, WHITE); // draw point using shape color
    }
};

//////////////////////////////////////////////
//                LINE
//////////////////////////////////////////////
class Line
{
private:
    Point P1, P2;
    int color;

public:
    // Default constructor
    Line() : P1(0,0), P2(0,0)
    {
        cout << "Line Default Constructor called\n";
    }

    // Parameterized constructor with Points
    Line(Point a, Point b, int c=BLUE) : P1(a), P2(b),color(c)
    {
        cout << "Line Parameterized Constructor called\n";
    }

    // Parameterized constructor with coordinates
    Line(int x1, int y1, int x2, int y2, int c=BLUE) : P1(x1, y1), P2(x2, y2),color(c)
    {
        cout << "Line Parameterized Constructor with coordinates called\n";
    }

    // Setters
    void setP1(Point a)
    {
        P1 = a;
    }
    void setP2(Point b)
    {
        P1 = b;
    }

    // Getters
    Point getP1()
    {
        return P1;
    }
    Point getP2()
    {
        return P2;
    }

    //override Draw from Shape
    void Draw()
    {
        setcolor(color);
        line(P1.getX(), P1.getY(), P2.getX(), P2.getY());
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
class Rect
{
private:
    Point tl;
    Point br;
    int color;

public:
    // Default constructor
    Rect() : tl(0,0), br(0,0)
    {
        cout << "Rectangle Default Constructor called\n";
    }

    // Parameterized constructor with Points
    Rect(Point topLeft, Point bottomRight, int c=RED) : tl(topLeft), br(bottomRight), color(c)
    {
        cout << "Rectangle Parameterized Constructor called\n";
    }

    // Parameterized constructor with coordinates
    Rect(int x1, int y1, int x2, int y2, int c=RED) : tl(x1, y1), br(x2, y2), color(c)
    {
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
        setcolor(color);
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
class Circle
{
private:
    Point center;
    int radius;
    int color;

public:

    Circle() : center(0,0), radius(0)
    {
        cout << "Circle Constructor ParaLess.. called ";
    }

    Circle(Point c, int r, int col=GREEN) : center(c), radius(r),color(col)
    {
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
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture
{
private:
    int cNum, rNum, lNum;
    Circle* pCircle;
    Rect* pRects;
    Line* pLine;

public:
    // Constructors
// Constructors
    Picture()
    {
        cNum = 0;
        rNum = 0;
        lNum = 0;
        pCircle = NULL;
        pRects = NULL;
        pLine = NULL;
    }

    Picture(int cn, int rn, int ln, Circle* pc, Rect* pr, Line* pl)
    {
        cNum = cn;
        rNum = rn;
        lNum = ln;
        pCircle = pc;
        pRects = pr;
        pLine = pl;
    }
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



int main()
{
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

    Picture myPic;
    myPic.setCircles(3, cirArr);
    myPic.setRects(2, recArr);
    myPic.setLines(2, linArr);

    myPic.paint();

    getch();
    closegraph();
    return 0;
}
