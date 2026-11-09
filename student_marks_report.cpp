#include <iostream>
using namespace std;

void readMarks(int marks[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " mark: ";
        cin >> marks[i];
    }
}

int findTotal(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    return sum;
}

double findAverage(int marks[], int n) {
    return findTotal(marks, n) / (double)n;
}

int findHighest(int marks[], int n) {
    int max = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > max) {
            max = marks[i];
        }
    }
    return max;
}

int findLowest(int marks[], int n) {
    int min = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] < min) {
            min = marks[i];
        }
    }
    return min;
}

int countPassed(int marks[], int n) {
    int passed = 0;
    for (int i = 0; i < n; i++) {
        if (marks[i] >= 40) {
            passed++;
        }
    }
    return passed;
}

void printReport(int marks[], int n) {
    int passed = countPassed(marks, n);

    cout << "\\n--- REPORT ---\\n";
    cout << "Total: " << findTotal(marks, n) << "\\n";
    cout << "Average: " << findAverage(marks, n) << "\\n";
    cout << "Highest: " << findHighest(marks, n) << "\\n";
    cout << "Lowest: " << findLowest(marks, n) << "\\n";
    cout << "Passed: " << passed << "\\n";
    cout << "Failed: " << n - passed << "\\n";
}

int main() {
    char repeat;

    do {
        int marks[100];
        int n = 0;

        while (n < 1 || n > 100) {
            cout << "Enter number of students (1-100): ";
            cin >> n;
        }

        readMarks(marks, n);
        printReport(marks, n);

        cout << "\\nRun again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
