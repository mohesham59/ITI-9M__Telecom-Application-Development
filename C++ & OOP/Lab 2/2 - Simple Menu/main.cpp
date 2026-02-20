#include <iostream>

using namespace std;

int main()
{
    int choice;
    cout << "Hello In The Our Coffee ^_^" << endl <<endl;
    cout << "Chick Our Menu ^_^ \n1. Ice Tea 20$\n2. Coffee 30$\n3. Juice 40$"<<endl<<endl;
    cout << "Please Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout<<"Your choice is Ice Tea => 20$ :)"<<endl;
        break;
    case 2:
        cout<<"Your choice is Coffee => 30$ :)"<<endl;
        break;
    case 3:
        cout<<"Your choice is Juice => 40$ :)"<<endl;
        break;
    default:
        cout<<"Your choice is unveiled";
    }
    return 0;
}
