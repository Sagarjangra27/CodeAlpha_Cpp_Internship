#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "===== CGPA Calculator =====" << endl;

    cout << "Enter the number of courses: ";
    cin >> n;

    float grade[n], credit[n];
    float totalCredits = 0, totalGradePoints = 0;

    // Input grades and credits
    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Grade Point: ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    // Semester GPA
    float semesterGPA = totalGradePoints / totalCredits;

    // Previous CGPA details
    float previousCGPA;
    float previousCredits;

    cout << "\nEnter Previous CGPA (Enter 0 if first semester): ";
    cin >> previousCGPA;

    cout << "Enter Total Previous Credits: ";
    cin >> previousCredits;

    // Overall CGPA
    float overallCGPA;

    if (previousCredits == 0)
    {
        overallCGPA = semesterGPA;
    }
    else
    {
        overallCGPA = ((previousCGPA * previousCredits) + totalGradePoints) /
                      (previousCredits + totalCredits);
    }

    // Display Result
    cout << "\n========== Result ==========" << endl;
    cout << left << setw(10) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(10) << i + 1
             << setw(15) << grade[i]
             << setw(15) << credit[i] << endl;
    }

    cout << "\nTotal Credits      : " << totalCredits << endl;
    cout << "Semester GPA       : " << fixed << setprecision(2) << semesterGPA << endl;
    cout << "Overall CGPA       : " << fixed << setprecision(2) << overallCGPA << endl;

    return 0;
}