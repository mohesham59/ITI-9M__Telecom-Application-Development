#include <graphics.h>
#include <iostream>
using namespace std;

//////////////////////////////////////////////
//                POINT
//////////////////////////////////////////////
class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int X, int Y) : x(X), y(Y) {}

    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }

    int getX() { return x; }
    int getY() { return y; }

    void Draw(int color = WHITE) {
        setcolor(color);
        putpixel(x, y, color);
    }
};

//////////////////////////////////////////////
//                LINE
//////////////////////////////////////////////
class Line {
private:
    Point p1, p2;

public:
    Line() {}
    Line(Point a, Point b) : p1(a), p2(b) {}

    void setP1(Point a) { p1 = a; }
    void setP2(Point b) { p2 = b; }

    Point getP1() { return p1; }
    Point getP2() { return p2; }

    void Draw(int color = WHITE) {
        setcolor(color);
        line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }
};

//////////////////////////////////////////////
//                RECTANGLE
//////////////////////////////////////////////
class Rect {
private:
    Point tl;  // top-left
    Point br;  // bottom-right

public:
    Rect() {}
    Rect(Point topLeft, Point bottomRight) : tl(topLeft), br(bottomRight) {}

    void setTL(Point p) { tl = p; }
    void setBR(Point p) { br = p; }

    Point getTL() { return tl; }
    Point getBR() { return br; }

    void Draw(int color = WHITE) {
        setcolor(color);
        rectangle(tl.getX(), tl.getY(), br.getX(), br.getY());
    }
};

//////////////////////////////////////////////
//                CIRCLE
//////////////////////////////////////////////
class Circle {
private:
    Point center;
    int radius;

public:
    Circle() : radius(0) {}
    Circle(Point c, int r) : center(c), radius(r) {}

    void setCenter(Point c) { center = c; }
    void setRadius(int r) { radius = r; }

    Point getCenter() { return center; }
    int getRadius() { return radius; }

    void Draw(int color = WHITE) {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

//////////////////////////////////////////////
//                MAIN
//////////////////////////////////////////////
int main() {

    // Initialize graphics window
    initwindow(800, 600, "Composition Example");

    // Make objects
    Point p1(100, 100);
    Point p2(300, 100);
    Line L(p1, p2);

    Rect R(Point(150, 150), Point(350, 300));

    Circle C(Point(500, 250), 80);

    // Draw all objects
    p1.Draw(YELLOW);
    p2.Draw(YELLOW);
    L.Draw(WHITE);

    R.Draw(GREEN);

    C.Draw(RED);

    // Wait for key
    getch();
    closegraph();

    return 0;
}
