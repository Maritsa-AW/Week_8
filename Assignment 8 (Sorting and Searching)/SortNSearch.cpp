#include <iostream>
#include <string>
#include <iomanip> // For setw
using namespace std;

struct Student {
    long long NISN;
    string Name;
    int Value;
};

// Function to display students' data
void displayStudents(Student students[], int count) {
    cout << left;
    cout << setw(15) << "NISN" << setw(30) << "Name" << "Value\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << setw(15) << students[i].NISN
             << setw(30) << students[i].Name
             << students[i].Value << endl;
    }
    cout << endl;
}

// Insertion sort for NISN (descending order)
void sortNISNDescending(Student students[], int count) {
    for (int i = 1; i < count; i++) {
        Student current = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].NISN < current.NISN) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = current;
    }
}

// Selection sort for Value (descending order)
void sortValueDescending(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j].Value > students[maxIdx].Value) {
                maxIdx = j;
            }
        }
        swap(students[i], students[maxIdx]);
    }
}

// Bubble sort for Value (descending order)
void bubbleSortValueDescending(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].Value < students[j + 1].Value) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Sequential search and update name
void searchAndRename(Student students[], int count, const string &newName) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].Value == 60) {
            students[i].Name = newName;
            found = true;
        }
    }
    if (found) {
        cout << "Name updated to " << newName << " for all students with Value: 60.\n";
    } else {
        cout << "No student found with Value 60.\n";
    }
}

// Binary search for a student by NISN
void binarySearchByNISN(Student students[], int count, long long targetNISN) {
    int low = 0, high = count - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].NISN == targetNISN) {
            cout << "Student found:\n";
            cout << "NISN: " << students[mid].NISN
                 << ", Name: " << students[mid].Name
                 << ", Value: " << students[mid].Value << endl;
            return;
        }
        if (students[mid].NISN < targetNISN) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << "Student with NISN " << targetNISN << " not found.\n";
}

int main() {
    Student students[] = {
        {9960312699, "Handi Ramadhan", 90},
        {9963959682, "Rio Alfandra", 55},
        {9950310962, "Ronaldo Valentino Uneputty", 80},
        {9970272750, "Achmad Yaumil Fadjri R.", 60},
        {9970293945, "Alivia Rahma Pramesti", 70},
        {9952382180, "Ari Lutfianto", 65},
        {9965653989, "Arief Budiman", 60}
    };
    int studentCount = sizeof(students) / sizeof(students[0]);

    // Sorting and displaying students by NISN
    cout << "Sorting by NISN in descending order using Insertion Sort:\n";
    sortNISNDescending(students, studentCount);
    displayStudents(students, studentCount);

    // Sorting and displaying students by Value using Selection Sort
    cout << "Sorting by Value in descending order using Selection Sort:\n";
    sortValueDescending(students, studentCount);
    displayStudents(students, studentCount);

    // Sorting and displaying students by Value using Bubble Sort
    cout << "Sorting by Value in descending order using Bubble Sort:\n";
    bubbleSortValueDescending(students, studentCount);
    displayStudents(students, studentCount);

    // Binary search for NISN = 9950310962
    cout << "Searching for student with NISN = 9950310962 using Binary Search:\n";
    binarySearchByNISN(students, studentCount, 9950310962);

    // Sequential search and rename students with Value = 60
    cout << "Updating names of all students with Value = 60 to 'Joko':\n";
    searchAndRename(students, studentCount, "Joko");
    displayStudents(students, studentCount);

    return 0;
}

