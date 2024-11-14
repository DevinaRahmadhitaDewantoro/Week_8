#include <iostream>
#include <string>
using namespace std;

struct Student {
    long long NISN;
    string Name;
    int Value;
};

// Function to display students' data
void display(Student studentsData[], int n) {
    for (int i = 0; i < n; i++) {
        cout << studentsData[i].NISN << " " << studentsData[i].Name << " " << studentsData[i].Value << endl;
    }
    cout << endl;
}

// Insertion sort for NISN (descending order)
void insertionSortNISN(Student studentData[], int n) {
    for (int j = 1; j < n; j++) {
        int i = j - 1;
        Student temp = studentData[j];
        while (i >= 0 && studentData[i].NISN < temp.NISN) {
            studentData[i + 1] = studentData[i];
            i--;
        }
        studentData[i + 1] = temp;
    }
}

// Insertion sort for Value (descending order)
void insertionSortValue(Student studentData[], int n) {
    for (int j = 1; j < n; j++) {
        int i = j - 1;
        Student temp = studentData[j];
        while (i >= 0 && studentData[i].NISN < temp.NISN) {
            studentData[i + 1] = studentData[i];
            i--;
        }
        studentData[i + 1] = temp;
    }
}


// Selection sort for NISN (descending order)
void selectionSortNISN(Student studentData[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (studentData[j].NISN > studentData[maxIdx].NISN) {
                maxIdx = j;
            }
        }
        Student temp = studentData[i];
        studentData[i] = studentData[maxIdx];
        studentData[maxIdx] = temp;
    }
}

// Selection sort for Value (descending order)
void selectionSortValue(Student studentData[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (studentData[j].Value > studentData[maxIdx].Value) {
                maxIdx = j;
            }
        }
        Student temp = studentData[i];
        studentData[i] = studentData[maxIdx];
        studentData[maxIdx] = temp;
    }
}

// Bubble sort for NISN (descending order)
void bubbleSortNISN(Student studentData[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (studentData[j].NISN < studentData[j + 1].NISN) {
                Student temp = studentData[j];
                studentData[j] = studentData[j + 1];
                studentData[j + 1] = temp;
            }
        }
    }
}

// Bubble sort for Value (descending order)
void bubbleSortValue(Student studentData[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (studentData[j].Value < studentData[j + 1].Value) {
                Student temp = studentData[j];
                studentData[j] = studentData[j + 1];
                studentData[j + 1] = temp;
            }
        }
    }
}

bool binarySearchNISN(Student studentData[], int n, long long targetNISN) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (studentData[mid].NISN == targetNISN) {
            // Found the student
            cout << "Found student with NISN " << targetNISN << ":\n";
            cout << "NISN: " << studentData[mid].NISN << ", Name: " << studentData[mid].Name << ", Value: " << studentData[mid].Value << endl;
            return true;
        }

        if (studentData[mid].NISN < targetNISN) {
            left = mid + 1; // Look in the right half
        } else {
            right = mid - 1; // Look in the left half
        }
    }

    // Not found
    cout << "No student found with NISN " << targetNISN << endl;
    return false;
}


// Sequential search to change name
bool sequentialSearchAndChangeName(Student studentData[], int n) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (studentData[i].Value == 60) {
            studentData[i].Name = "Joko";
            found = true;
        }
    }
    return found;
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
    int n = sizeof(students) / sizeof(students[0]);

    // Test 1: Insertion Sort by NISN
    insertionSortNISN(students, n);
    if (students[0].NISN > students[1].NISN) {
        cout << "Test 1 (Insertion Sort by NISN): Passed\n";
    } else {
        cout << "Test 1 (Insertion Sort by NISN): Failed\n";
    }

    // Test 2: Selection Sort by NISN
    selectionSortNISN(students, n);
    if (students[0].NISN > students[1].NISN) {
        cout << "Test 2 (Selection Sort by NISN): Passed\n";
    } else {
        cout << "Test 2 (Selection Sort by NISN): Failed\n";
    }

    // Test 3: Bubble Sort by NISN
    bubbleSortNISN(students, n);
    if (students[0].NISN > students[1].NISN) {
        cout << "Test 3 (Bubble Sort by NISN): Passed\n";
    } else {
        cout << "Test 3 (Bubble Sort by NISN): Failed\n";
    }

    // Test 4: Insertion Sort by Value
    insertionSortValue(students, n);
    if (students[0].Value > students[1].Value) {
        cout << "Test 4 (Insertion Sort by Value): Passed\n";
    } else {
        cout << "Test 4 (Insertion Sort by Value): Failed\n";
    }

    // Test 5: Selection Sort by Value
    selectionSortValue(students, n);
    if (students[0].Value > students[1].Value) {
        cout << "Test 5 (Selection Sort by Value): Passed\n";
    } else {
        cout << "Test 5 (Selection Sort by Value): Failed\n";
    }

    // Test 6: Bubble Sort by Value
    bubbleSortValue(students, n);
    if (students[0].NISN > students[1].NISN) {
        cout << "Test 6 (Bubble Sort by Value): Passed\n";
    } else {
        cout << "Test 6 (Bubble Sort by Value): Failed\n";
    }

    // Test 7: Binary Search for NISN 9950310962
    if (binarySearchNISN(students, n, 9950310962)) {
        cout << "Test 7 (Binary Search for NISN 9950310962): Passed\n";
    } else {
        cout << "Test 7 (Binary Search for NISN 9950310962): Failed\n";
    }

    // Test 8: Sequential Search to change Value 60 to "Joko"
    if (sequentialSearchAndChangeName(students, n)) {
        cout << "Test 8 (Sequential Search and Name Change): Passed\n";
    } else {
        cout << "Test 8 (Sequential Search and Name Change): Failed\n";
    }

    return 0;
} 