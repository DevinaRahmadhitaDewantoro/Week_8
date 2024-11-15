#include <iostream>
#include <string>
using namespace std;

struct Student {
    long long NISN;
    string Name;
    int Value;
};

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

void insertionSortValue(Student studentData[], int n) {
    for (int j = 1; j < n; j++) {
        int i = j - 1;
        Student temp = studentData[j];
        while (i >= 0 && studentData[i].Value < temp.Value) { 
            studentData[i + 1] = studentData[i];
            i--;
        }
        studentData[i + 1] = temp;
    }
}

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
            return true;
        }

        if (studentData[mid].NISN < targetNISN) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

void sequentialSearchAndChangeName(Student studentData[], int n) {
    for (int i = 0; i < n; i++) {
        if (studentData[i].Value == 60) {
            studentData[i].Name = "Joko";
        }
    }
}

bool isSortedByNISN(Student studentData[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (studentData[i].NISN < studentData[i + 1].NISN) {
            return false;
        }
    }
    return true;
}

bool isSortedByValue(Student studentData[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (studentData[i].Value < studentData[i + 1].Value) {
            return false;
        }
    }
    return true;
}

bool allValue60NamedJoko(Student studentData[], int n) {
    for (int i = 0; i < n; i++) {
        if (studentData[i].Value == 60 && studentData[i].Name != "Joko") {
            return false;
        }
    }
    return true;
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

    cout << "Test 1: Insertion Sort by NISN\n";
    insertionSortNISN(students, n);
    if (isSortedByNISN(students, n)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    cout << "Test 2: Insertion Sort by Value\n";
    insertionSortValue(students, n);
    if (isSortedByValue(students, n)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    cout << "Test 3: Binary Search for Ronaldo's NISN\n";
    if (binarySearchNISN(students, n, 9950310962)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    cout << "Test 4: Selection Sort by NISN\n";
    selectionSortNISN(students, n);
    if (isSortedByNISN(students, n)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    cout << "Test 5: Selection Sort by Value\n";
    selectionSortValue(students, n);
    if (isSortedByValue(students, n)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    cout << "Test 6: Bubble Sort by NISN\n";
    bubbleSortNISN(students, n);
    if (isSortedByNISN(students, n)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    cout << "Test 7: Bubble Sort by Value\n";
    bubbleSortValue(students, n);
    if (isSortedByValue(students, n)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    cout << "Test 8: Change Name to 'Joko' for Students with Value 60\n";
    sequentialSearchAndChangeName(students, n);
    if (allValue60NamedJoko(students, n)) {
        cout << "Result: Test Passed\n\n";
    } else {
        cout << "Result: Test Failed\n\n";
    }

    return 0;
}
