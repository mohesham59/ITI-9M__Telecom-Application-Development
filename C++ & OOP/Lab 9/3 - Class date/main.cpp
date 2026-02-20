#include <iostream>

using namespace std;
class Date
{
private:
    int Day, Month, Year;

public:
    ///constructors
    Date();
    Date(int DD, int MM, int YY);

    ///Copy Constructor
    Date(const Date& Time);

    ///Function Display
    void printDate();

    /// Functions Operation
    //int operator-(const Date& Time);

    int operator-(const Date& Time);
    Date operator+(int days);

    Date& operator++();      // Prefix ++d
    Date operator++(int);   // Postfix d++

    void operator=(const Date& Time);

    bool operator==(const Date& Time);

    operator int();         // Casting operator

    int operator[](char ch);
};

//--------------------------------------------------
//--------------------------------------------------

int main()
{
    cout << "===== PROGRAM START =====\n";

    cout << "\n===== Default constructor =====\n";
    Date D1;               // Default constructor
    cout<<"D1: ";
    D1.printDate();

    cout << "\n===== Parameterized constructor =====\n";
    Date D2(3, 12, 2025);  // Parameterized constructor
    cout<<"D2: ";
    D2.printDate();

    Date D3(6, 4, 2002);
    cout<<"D3: ";
    D3.printDate();

    cout << "\n===== Copy constructor =====\n";
    Date D4(D2);           // Copy constructor
    cout<<"D4: ";
    D4.printDate();
/*
    cout << "\n===== PERFORMING OPERATION: D2 - D3 =====\n";
    Date diff;
    diff = D2 - D3;
    cout<<"Diff: ";
    diff.printDate();
*/
    cout << "\n===== PERFORMING OPERATION: D2 - D3 =====\n";
    int diff = D2 - D3;
    cout << "Diff (Days): " << diff << endl;

    cout << "\n===== PERFORMING OPERATION: D2 + 10 =====\n";
    D1 = D2 + 10;
    cout<<"D1: ";
    D1.printDate();

    cout << "\n===== Prefix ++D1 =====\n";
    ++D1;
    D1.printDate();

    cout << "\n===== Postfix D1++ =====\n";
    D1++;
    D1.printDate();
    cout << "\n===== Equal D3 = D4 =====\n";
    D3 = D4;
    cout<<"\nD3 After Equal D4: \n";
    D3.printDate();
    cout << "\n===== Equality Check =====\n";
    cout << (D3 == D4 ? "Equal" : "Not Equal") << endl;

    cout << "\n===== Casting to int =====\n";
    int Casting = (int)D2;
    cout << "Compressed Date = " << Casting << endl;

    cout << "\n===== Using [] Operator =====\n";
    cout << "D2['d'] = " << D2['d'] << endl;
    cout << "D2['m'] = " << D2['m'] << endl;
    cout << "D2['y'] = " << D2['y'] << endl;

    return 0;
}

//--------------------------------------------------
//--------------------------------------------------

///constructors
Date :: Date()
{
    this -> Day = 0;
    this -> Month = 0;
    this -> Year = 0;
    cout << "Default Constructor called\n";
    cout << "------------------------\n";
}

Date :: Date(int DD, int MM, int YY)
{
    this -> Day = DD;
    this -> Month = MM;
    this -> Year = YY;
    cout << "Parameterized Constructor called\n";
    cout << "------------------------\n";
}

///Copy Constructor
Date :: Date(const Date& Time)
{
    this -> Day = Time.Day;
    this -> Month = Time.Month;
    this -> Year = Time.Year;
    cout << "Copy Constructor, Copied: \n";
    cout << "------------------------\n";
}

/// Member function to Display
void Date :: printDate()
{
    cout<<"Day/Month/Year"<<endl;
    cout<< this->Day <<" / " << this->Month <<" / "<< this->Year<<endl;
}

//--------------------------------------------------
//--------------------------------------------------

/// Functions Operation
/*
Date Date :: operator-(const Date& Time)  // operator - => diff = d2 - d3;
{
    Date result;
    int total1 = this->Year * 365 + this->Month * 30 + this->Day;
    int total2 = Time.Year * 365 + Time.Month * 30 + Time.Day;
    int diff = total1 - total2; // Days

    result.Year = diff / 365;
    diff = diff % 365;

    result.Month = diff / 30;
    diff = diff % 30;

    result.Day = diff;

    return result;
    cout << "------------------------\n";
}
*/
/// Operator -  (returns number of days)
int Date::operator-(const Date& Time)
{
    int total1 = Year * 365 + Month * 30 + Day;
    int total2 = Time.Year * 365 + Time.Month * 30 + Time.Day;

    return total1 - total2;
}

/// Operator +  (add days to date)
Date Date::operator+(int days)
{
    Date result= *this;

    result.Day += days;

    while (result.Day > 30)
    {
        result.Day -= 30;
        result.Month++;
    }
    while (result.Month > 12)
    {
        result.Month -= 12;
        result.Year++;
    }

    return result;
}

/// Prefix ++d
Date& Date::operator++()
{
    Day++;
    if (Day > 30) { Day = 1; Month++; }
    if (Month > 12) { Month = 1; Year++; }

    return *this;
}

/// Postfix d++
Date Date::operator++(int)
{
    Date temp = *this;
    ++(*this);   // call prefix
    return temp;  //date by value
}

/// Assignment operator D1 = D2
void Date::operator=(const Date& Time) //Time D1
{
    cout << "Assignment Operator Called\n";
    Day = Time.Day;
    Month = Time.Month;
    Year = Time.Year;
}

/// Equality operator
bool Date::operator==(const Date& Time)
{
    return Day == Time.Day && Month == Time.Month && Year == Time.Year;
}

/// Casting operator  → int
/// Format: YYYYMMDD
Date::operator int()
{
    return Year * 10000 + Month * 100 + Day;
}

/// Operator []
/// 'd' → Day , 'm' → Month, 'y' → Year
int Date::operator[](char ch)
{
    if (ch == 'd' || ch == 'D') return Day;
    if (ch == 'm' || ch == 'M') return Month;
    if (ch == 'y' || ch == 'Y') return Year;
    return -1;
}
