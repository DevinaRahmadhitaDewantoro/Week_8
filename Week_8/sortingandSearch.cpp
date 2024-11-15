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
void display(Student studentsData[], int n) {
    cout << left;
    cout << setw(15) << "NISN" << setw(30) << "Name" << "Value\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(15) << studentsData[i].NISN
             << setw(30) << studentsData[i].Name
             << studentsData[i].Value << endl;
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
        while (i >= 0 && studentData[i].Value < temp.Value) { 
            studentData[i + 1] = studentData[i];
            i--;
        }
        studentData[i + 1] = temp;
    }
}

// Selection sort for NISN (descending order)
void selectionSortNISN(Student studentData[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (studentData[j].NISN > studentData[minIdx].NISN) {
                minIdx = j;
            }
        }
        Student temp = studentData[i];
        studentData[i] = studentData[minIdx];
        studentData[minIdx] = temp;
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

void sequentialSearchAndChangeName(Student studentData[], int n) {
    long long targetNISN;
    
    cout << "Enter NISN to change Name to 'Joko' for students with Value 60 (Enter -1 to stop): \n";
    
    // Ask for input until -1 is entered
    while (true) {
        cout << "Enter NISN: ";
        cin >> targetNISN;

        // If the user enters -1, break the loop
        if (targetNISN == -1) {
            break;
        }

        bool found = false; // Reset the 'found' flag for each iteration
        
        for (int i = 0; i < n; i++) {
            if (studentData[i].NISN == targetNISN && studentData[i].Value == 60) {
                studentData[i].Name = "Joko"; // Change name to "Joko"
                found = true;
                cout << "Name changed to Joko for NISN: " << studentData[i].NISN << endl;
                break; // Exit the loop after making the change
            }
        }
        
        if (!found) {
            cout << "No student found with NISN " << targetNISN << " and Value 60.\n";
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

    // Sort the students by NISN in descending order before searching
    insertionSortNISN(students, n);

    // First display: insertion Sort by NISN in descending order
    cout << "Display 1: insertion Sorted by NISN (Descending)" << endl;
    display(students, n);

    // Second display: insertion Sort by Value in descending order
    insertionSortValue(students, n);
    cout << "Display 2: insertion Sorted by Value (Descending)" << endl;
    display(students, n);

    // Third display: selection Sort by NISN in descending order
    selectionSortNISN(students, n);
    cout << "Display 3: selection Sorted by NISN (Descending)" << endl;
    display(students, n);

    // Fourth display: selection Sort by Value in descending order
    selectionSortValue(students, n);
    cout << "Display 4: selection Sorted by Value (Descending)" << endl;
    display(students, n);

    // Fifth display: bubble Sort by NISN in descending order
    bubbleSortNISN(students, n);
    cout << "Display 5: bubble Sorted by NISN (Descending)" << endl;
    display(students, n);

    // Sixth display: bubble Sort by Value in descending order
    bubbleSortValue(students, n);
    cout << "Display 6: bubble Sorted by Value (Descending)" << endl;
    display(students, n);

    // Change students with Value 60 to "Joko"
    cout << "Display 7: After changing students with Value 60 to Joko" << endl;
    sequentialSearchAndChangeName(students, n);  // Sequential search happens here
    display(students, n);

    // Perform search for NISN after sorting
    long long targetNISNToSearch;
    cout << "Insert key of data (NISN) to search: ";
    cin >> targetNISNToSearch;
    binarySearchNISN(students, n, targetNISNToSearch);

    return 0;
}
