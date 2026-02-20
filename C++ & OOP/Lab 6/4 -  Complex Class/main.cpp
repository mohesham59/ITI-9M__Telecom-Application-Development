#include <iostream>

using namespace std;

struct cmplx {

    private:
        int real;
        int img;

    public:
        void real_set(int x)
        {
        real = x;
        }
        void img_set(int y)
        {
        img = y;
        }
        int real_get()
        {
        return real;
        }
        int img_get()
        {
        return img;
        }
};
cmplx add(cmplx c1, cmplx c2)
{
    cmplx result;
    result.real_set(c1.real_get() + c2.real_get());
    result.img_set(c2.img_get() + c1.img_get());
    return result;
}

cmplx subtract(cmplx c1, cmplx c2)
{
    cmplx result;
    result.real_set(c1.real_get() - c2.real_get());
    result.img_set(c2.img_get() - c1.img_get());
    return result;
}

void print(cmplx c)
{

    if (c.img_get() < 0)
    {
        cout << c.real_get() << c.img_get() << "i" << endl;
    }
    else
    {
        cout << c.real_get() << "+" << c.img_get() << "i" << endl;
    }

}

int main()
{

    cmplx c1,c2,result;
    int x,y;
    cout << "enter the real number and imaginary number of c1 respectively: " << endl;
    cin >> x >> y;
    c1.img_set(y);
    c1.real_set(x);

    cout << "enter the real number and imaginary number of c2 respectively: " << endl;
    cin >> x >> y;
    c2.img_set(y);
    c2.real_set(x);

    result = add(c1,c2);
    print(result);
    result = subtract(c1,c2);
    print(result);

    return 0;
}



