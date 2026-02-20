#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <MyLibrary.h>
using namespace std;

#define LEFT_ARROW  75
#define RIGHT_ARROW 77
#define HOME_KEY    71
#define END_KEY     79
#define ESC_KEY     27
#define ENTER_KEY   13
#define BACKSPACE   8

int main()
{
    const int SIZE = 100;
    char text[SIZE] = {0};
    int length = 0;
    int cursor = 0;

    cout << "Single Line Editor (ESC to exit)" << endl;
    cout << "================================" << endl;

    while (true)
    {
        int ch = _getch();

        if (ch == 224 || ch == -32 || ch == 0)
        {
            ch = _getch();
            switch (ch)
            {
                case LEFT_ARROW:
                    if (cursor > 0) cursor--;
                    break;

                case RIGHT_ARROW:
                    if (cursor < length) cursor++;
                    break;

                case HOME_KEY:
                    cursor = 0;
                    break;

                case END_KEY:
                    cursor = length;
                    break;
            }
        }
        else if (ch == ESC_KEY)
        {
            break;
        }
        else if (ch == ENTER_KEY)
        {
            cout << "\nFinal Text: " << text << "\n";
            break;
        }
        else if (ch == BACKSPACE)  // BACKSPACE
        {
            if (cursor > 0)
            {
                for (int i = cursor - 1; i < length - 1; i++)
                {
                    text[i] = text[i + 1];
                }
                text[length - 1] = '\0';
                cursor--;
                length--;
            }
        }
        else       // Enter Char
        {
            if (length < SIZE - 1)
            {
                for (int i = length; i > cursor; i--)
                {
                    text[i] = text[i - 1];
                }
                text[cursor] = ch;
                cursor++;
                length++;
                text[length] = '\0';
            }
        }

        clrscr();
        cout << "Single Line Editor (ESC to exit)\n";
        cout << "================================\n";
        cout << text << endl;

        for (int i = 0; i < cursor; i++) cout << " ";
        cout << "^";
    }

    return 0;
}
