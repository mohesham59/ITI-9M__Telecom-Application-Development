#include <iostream>
#include <MyLibrary.h>
#include <conio.h>

using namespace std;

int main()
{
    string menu[3]= {"New", "Dispaly", "Exit"};
    int cur = 0;
    char ch=' ';
    int ExitFlag = 0;

    do
    {
        textattr(0x07);
        clrscr();
        for (int i=0; i<3; i++)
        {
            if (cur == i)
            {
                textattr(0x70);
            }
            else
            {
                textattr(0x07);
            }
            gotoxy(55, i*3+7);
            cout<<menu[i];
        }

        ch = _getch();
        switch(ch)
        {
            cout<<(int)ch;
            case -32:
            case 0:
            case 224:
                ch = _getch();
                switch (ch)
                    {
                        case 72: // UP
                            cur --;
                            if (cur <0)
                                cur = 2;
                        break;

                        case 80: //Down
                            cur ++;
                            if (cur > 2)
                                cur = 0;
                        break;

                        case 71: //Home
                            cur = 0;
                        break;

                        case 79: //end
                            cur = 2;
                        break;
                    }
            break;

            case 13: //enter
                switch(cur)
                {
                    case 0: //new
                        clrscr();
                        cout<<"\nThis is New page ... ^_^";
                        _getch();
                    break;

                    case 1: //Display
                        clrscr();
                        cout<<"\nThis is Display page ... ^_^";
                        _getch();
                    break;

                    case 2: //Exit
                        ExitFlag = 1;
                        textattr(0x07);
                        clrscr();
                        cout<<"\nBye Bye ... ^_^";
                        _getch();
                    break;

                }
            break;

            case 7: //ESC
                ExitFlag = 1;
                textattr(0x07);
                clrscr();
                cout<<"\nBye Bye ... ^_^";
                _getch();
            break;


        }
    } while(ExitFlag == 0);
    cout << endl;

    return 0;
}
