#include <iostream>
using namespace std;

int main() {
    int students; // number of rows
    cout << "Enter number of students: ";
    cin >> students;

    int** arr = new int*[students]; // pointer to array of pointers
    int* subjects = new int[students]; // store number of subjects for each student

    // Input degrees
    for (int i = 0; i < students; i++)
    {
        cout << "Enter number of subjects for student " << i+1 << ": ";
        cin >> subjects[i];

        arr[i] = new int[subjects[i]]; // allocate memory for this student's subjects

        cout << "Enter " << subjects[i] << " degrees:\n";
        for (int j = 0; j < subjects[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Display
    cout << "\nJagged array of students' degrees:\n";
    for (int i = 0; i < students; i++)
    {
        cout << "Student " << i+1 << ": ";
        for (int j = 0; j < subjects[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < students; i++)
        delete[] arr[i];
    delete[] arr;
    delete[] subjects;

    return 0;
}
