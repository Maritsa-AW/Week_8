#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>  // For assertions
using namespace std;

struct Student {
    long long NISN;
    string Name;
    int Value;
};

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

void bubbleSortValueDescending(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].Value < students[j + 1].Value) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

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

void testSortNISNDescending() {
    Student students[] = {
        {9960312699, "Handi Ramadhan", 90},
        {9963959682, "Rio Alfandra", 55},
        {9950310962, "Ronaldo Valentino Uneputty", 80}
    };
    int studentCount = sizeof(students) / sizeof(students[0]);

    sortNISNDescending(students, studentCount);
    // Check if the students are sorted by NISN in descending order
    assert(students[0].NISN == 9960312699);  
    assert(students[1].NISN == 9963959682);  
    assert(students[2].NISN == 9950310962);  

    cout << "Sort by NISN test passed.\n";
}

void testSortValueDescending() {
    Student students[] = {
        {9960312699, "Handi Ramadhan", 90},
        {9963959682, "Rio Alfandra", 55},
        {9950310962, "Ronaldo Valentino Uneputty", 80}
    };
    int studentCount = sizeof(students) / sizeof(students[0]);

    sortValueDescending(students, studentCount);
    // Check if the students are sorted by Value in descending order
    assert(students[0].Value == 90);  
    assert(students[1].Value == 80);  
    assert(students[2].Value == 55);  

    cout << "Sort by Value test passed.\n";
}

void testBubbleSortValueDescending() {
    Student students[] = {
        {9960312699, "Handi Ramadhan", 90},
        {9963959682, "Rio Alfandra", 55},
        {9950310962, "Ronaldo Valentino Uneputty", 80}
    };
    int studentCount = sizeof(students) / sizeof(students[0]);

    bubbleSortValueDescending(students, studentCount);
    // Check if the students are sorted by Value in descending order
    assert(students[0].Value == 90);  
    assert(students[1].Value == 80);  
    assert(students[2].Value == 55);  

    cout << "Bubble Sort by Value test passed.\n";
}

void testSearchAndRename() {
    Student students[] = {
        {9960312699, "Handi Ramadhan", 60},
        {9963959682, "Rio Alfandra", 60},
        {9950310962, "Ronaldo Valentino Uneputty", 80}
    };
    int studentCount = sizeof(students) / sizeof(students[0]);

    searchAndRename(students, studentCount, "Joko");

    // Check if the students with Value 60 have been renamed
    assert(students[0].Name == "Joko");
    assert(students[1].Name == "Joko");

    cout << "Search and Rename test passed.\n";
}

void testBinarySearchByNISN() {
    Student students[] = {
        {9960312699, "Handi Ramadhan", 90},
        {9963959682, "Rio Alfandra", 55},
        {9950310962, "Ronaldo Valentino Uneputty", 80}
    };
    int studentCount = sizeof(students) / sizeof(students[0]);

    binarySearchByNISN(students, studentCount, 9960312699);  // Test binary search with a valid NISN
    binarySearchByNISN(students, studentCount, 1234567890);  // Test binary search with an invalid NISN
}

int main() {
    // Run the tests
    testSortNISNDescending();
    testSortValueDescending();
    testBubbleSortValueDescending();
    testSearchAndRename();
    testBinarySearchByNISN();  // Added binary search test
    
    return 0;
}

