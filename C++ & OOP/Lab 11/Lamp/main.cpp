#include <iostream>
#include <graphics.h>
using namespace std;
class Point
{
    int X, Y;
public:
    Point()
    {
        X=Y=0;
        cout << "Parameterless Point Constructor called " << this << endl;
    }
    Point(const Point& p)
    {
        X=p.X;
        Y=p.Y;
        cout << "One parameter Point Copy Constructor called " << this << endl;
    }
    Point(int x, int y)
    {
        X=x;
        Y=y;
        cout << "Two parameters Point Constructor called " << this << endl;
    }
    ~Point()
    {
        cout << "Point Destructor called " << this << endl;
    }
    void setX(int x)
    {
        X=x;
    }
    float getX()
    {
        return X;
    }
    void setY(int y)
    {
        Y=y;
    }
    float getY()
    {
        return Y;
    }
};

class Rect
{
    Point UL, LR;
public:
    Rect() : UL(), LR()
    {
        cout << "Parameterless Rectangle Constructor called " << this << endl;
    }
    Rect(Point p1, Point p2) : UL(p1), LR(p2)
    {
        cout << "Two parameters Rectangle Constructor called " << this << endl;
    }
    Rect(int x1, int y1, int x2, int y2) : UL(x1, y1), LR(x2, y2)
    {
        cout << "Four parameters Rectangle Constructor called " << this << endl;
    }
    ~Rect()
    {
        cout << "Destructor Rectangle called " << this << endl;
    }
    void Draw()
    {
        setcolor(BLUE);
        rectangle(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};
class Line
{
    Point P1, P2;
public:
    Line() : P1(), P2()
    {
        cout << "Parameterless Line Constructor called " << this << endl;
    }
    Line(Point p1, Point p2) : P1(p1), P2(p2)
    {
        cout << "Two parameters Line Constructor called " << this << endl;
    }
    Line(int x1, int y1, int x2, int y2) : P1(x1, y1), P2(x2, y2)
    {
        cout << "Four parameters Line Constructor called " << this << endl;
    }
    ~Line()
    {
        cout << "Destructor Line called " << this << endl;
    }
    void Draw()
    {
        line(P1.getX(), P1.getY(), P2.getX(), P2.getY());
    }
};
class Circle
{
    Point C;
    int rad;
public:
    Circle() : C()
    {
        rad=0;
        cout << "Parameterless Circle Constructor called " << this << endl;
    }
    Circle(Point c, int r) : C(c)
    {
        rad=r;
        cout << "Two parameters Circle Constructor called " << this << endl;
    }
    Circle(int x, int y, int r) : C(x, y)
    {
        rad=r;
        cout << "Three parameters Circle Constructor called " << this << endl;
    }
    ~Circle()
    {
        cout << "Destructor Circle called " << this << endl;
    }
    void Draw()
    {
        //setcolor(RED);
        circle(C.getX(), C.getY(), rad);
    }
};
int main()
{
    int dx=50, lx=100, ly=200;
    Line Leg1(dx+250, 500, dx+250, 600);
    Line Leg2(dx+330, 500, dx+330, 600);
    Line Arm1(dx+350, 400, dx+400, 450);
    Line Arm2(dx+230, 400, dx+180, 400);
    Line ArmDown(dx+180, 400, dx+120, 400);
    Line ArmUp(dx+180, 400, dx+150, 350);
    Rect Body(dx+230, 350, dx+350, 500);
    Circle Face(dx+290, 300, 50);

    Line WireOff(150, 250, dx+150, 350);
    Line WireOn(150, 250, dx+120, 400);
    //Circle Lamp(lx, ly+15, 30);
    Line Tr1(lx, ly-50, lx+70, ly+50);
    Line Tr2(lx, ly-50, lx-70, ly+50);
    Line Tr3(lx-70, ly+50, lx+70, ly+50);
    Rect Rod(lx-10, ly+50, lx+10,ly+150);
    Rect Base(lx-70, ly+150, lx+70, ly+180);

    initwindow(480, 640);
    // -------------------------
    // Draw Legs, Arms, Face, Body
    // -------------------------
    setcolor(BROWN);          // Legs color
    Leg1.Draw();              // Draw left leg
    Leg2.Draw();              // Draw right leg

    setcolor(CYAN);           // Arms color
    Arm1.Draw();              // Draw first arm
    Arm2.Draw();              // Draw second arm

    setcolor(YELLOW);         // Face color
    Face.Draw();              // Draw face

    setcolor(WHITE);          // Eyes and fill color
    setfillstyle(SOLID_FILL, WHITE);

    // Draw eyes
    fillellipse(dx+270, 290, 5, 10);  // Left eye
    fillellipse(dx+310, 290, 5, 10);  // Right eye

    // Draw mouth (arc)
    //arc(dx+290, 310, 200, 340, 20); // Smile (commented)
    arc(dx+290, 330, 20, 160, 20);     // Sad

    setcolor(MAGENTA);        // Body color
    Body.Draw();              // Draw body

    setcolor(LIGHTGRAY);      // Wire off color
    WireOff.Draw();

    setcolor(LIGHTBLUE);      // Triangle color
    Tr1.Draw();
    Tr2.Draw();
    Tr3.Draw();

    setcolor(BLUE);           // Rod color
    Rod.Draw();

    setcolor(DARKGRAY);       // Base color
    Base.Draw();

    setcolor(GREEN);          // Upper arm color
    ArmUp.Draw();

    // -------------------------
    // Animation loop
    // -------------------------
    char togg = 1, escChar=0; // Toggle variable for animation, escChar for exit
    while(escChar!=27)        // Run until ESC key (27) is pressed
    {
        escChar = getch();    // Get user input

        // Erase previous mouth
        setcolor(BLACK);
        arc(dx+290, 330, 20, 160, 20);  // Erase sad
        arc(dx+290, 310, 200, 340, 20); // Erase smile

        // Redraw arms
        ArmDown.Draw();
        ArmUp.Draw();

        // Redraw wires
        WireOff.Draw();
        WireOn.Draw();

        if(togg) // First state
        {
            setfillstyle(SOLID_FILL,YELLOW);
            fillellipse(lx, ly+15, 30, 30 ); // Lamp ON
            setcolor(WHITE);
            arc(dx+290, 310, 200, 340, 20);  // Draw smile
            setcolor(GREEN);
            ArmDown.Draw();                  // Update arm
            setcolor(WHITE);
            WireOn.Draw();                   // Draw wire ON
            togg = 0;                        // Switch state
        }
        else      // Second state
        {
            setfillstyle(SOLID_FILL,BLACK);
            fillellipse(lx, ly+15, 30, 30 ); // Lamp OFF
            setcolor(WHITE);
            arc(dx+290, 330, 20, 160, 20);  // Draw sad
            setcolor(GREEN);
            ArmUp.Draw();                    // Update arm
            setcolor(WHITE);
            WireOff.Draw();                  // Draw wire OFF
            togg = 1;                        // Switch state
        }
    }

    closegraph();
    return 0;
}
