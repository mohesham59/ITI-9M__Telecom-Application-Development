#include <iostream>
using namespace std;

int main() {
    char ch;
    int alphabetCount = 0;
    int wordCount = 0;
    bool inWord = false;

    cout << "Enter a sentence: ";

    while (true)
    {
        ch = cin.get();
        if (ch == '\n')
            break;

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            alphabetCount++;
            if (!inWord)
            {
                inWord = true;
                wordCount++;
            }
        }
        else if (ch == ' ' || ch == '\t')
        {
            inWord = false;
        }
        else
        {
            inWord = false;
        }
    }

    cout << "Number of alphabets: " << alphabetCount << endl;
    cout << "Number of words: " << wordCount << endl;

    return 0;
}
