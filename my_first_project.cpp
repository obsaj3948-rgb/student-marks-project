#include <iostream>
#include <iomanip> // Needed for setw()

using namespace std;

int main() {
    char names[5][20];
    int marks[5][3];
    int topStudentIndex = 0;
    float highestAvg = 0;

    // 1. Get data for each student
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for student " << (i + 1) << ":" << endl;
        
        cout << "Name: ";
        cin.getline(names[i], 20);

        int total = 0;
        for (int j = 0; j < 3; j++) {
            cout << "Mark " << (j + 1) << ": ";
            cin >> marks[i][j];
            total += marks[i][j];
        }

        // Calculate average for this student
        float avg = total / 3.0;

        // Check if this student has the highest average
        if (i == 0 || avg > highestAvg) {
            highestAvg = avg;
            topStudentIndex = i;
        }

        // Clear input buffer before next getline()
        cin.ignore();
    }

    // 2. Print the table header
    cout << "\n\n--- MARK SHEET ---" << endl;
    cout << left << setw(12) << "Name" 
         << setw(6) << "M1" 
         << setw(6) << "M2" 
         << setw(6) << "M3" 
         << setw(8) << "Total" 
         << setw(6) << "Avg" << endl;
    
    cout << "----------------------------------------" << endl;

    // 3. Print each student's row
    for (int i = 0; i < 5; i++) {
        int total = marks[i][0] + marks[i][1] + marks[i][2];
        float avg = total / 3.0;

        cout << left << setw(12) << names[i] 
             << setw(6) << marks[i][0] 
             << setw(6) << marks[i][1] 
             << setw(6) << marks[i][2] 
             << setw(8) << total 
             << fixed << setprecision(1) << setw(6) << avg << endl;
    }

    cout << "----------------------------------------" << endl;

    // 4. Show the top student
    cout << "Top student: " << names[topStudentIndex] << endl;

    return 0;
}