#include <iostream>
#include <cstring>
#include <iomanip> 

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_NAME_LENGTH = 50;
const int MAX_COURSE_LENGTH = 50;

struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char course[MAX_COURSE_LENGTH];
};

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to center text
void printCentered(const string &text, int width) {
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; ++i) {
        cout << " ";
    }
    cout << text << endl;
}

// Function to check if ID is unique
bool isUniqueID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return false;
        }
    }
    return true;
}

// Function to insert a new student record
void insertStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printCentered("Student record list is full.", 100);
        return;
    }

    int id, age;
    char name[MAX_NAME_LENGTH], course[MAX_COURSE_LENGTH];

    printCentered("Enter Student ID: ", 100);
    cin >> id;
    while (!isUniqueID(id)) {
        printCentered("ID already exists. Enter a unique Student ID: ", 100);
        cin >> id;
    }
    students[studentCount].id = id;

    cin.ignore(); 

    printCentered("Enter Student Name: ", 100);
    cin.getline(students[studentCount].name, MAX_NAME_LENGTH);

    printCentered("Enter Student Age: ", 100);
    cin >> students[studentCount].age;
    while (cin.fail() || students[studentCount].age <= 0 || students[studentCount].age > 100) {
        cin.clear(); 
        cin.ignore(1000, '\n'); 
        printCentered("Invalid age. Please enter a valid age (1-100): ", 100);
        cin >> students[studentCount].age;
    }
    cin.ignore();

    printCentered("Enter Student Course: ", 100);
    cin.getline(students[studentCount].course, MAX_COURSE_LENGTH);

    studentCount++;
    printCentered("Student record inserted successfully.", 100);
}

// Function to view all student records
void viewAllStudents() {
    if (studentCount == 0) {
        printCentered("No student records found.", 100);
        return;
    }
    printCentered("ID\tName\t\tAge\tCourse", 100);
    printCentered("-------------------------------------------", 100);
    for (int i = 0; i < studentCount; i++) {
        cout << setw(25) << setfill(' ') << students[i].id << "\t" 
             << setw(25) << setfill(' ') << students[i].name << "\t\t" 
             << setw(25) << setfill(' ') << students[i].age << "\t" 
             << setw(25) << setfill(' ') << students[i].course << endl;
    }
}

// Function to search for a student record by ID
void searchStudentByID() {
    int id;
    printCentered("Enter Student ID to search: ", 100);
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << setw(25) << setfill(' ') << "ID: " << students[i].id << ", Name: " << students[i].name
                 << ", Age: " << students[i].age << ", Course: " << students[i].course << endl;
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Function to search for a student record by name
void searchStudentByName() {
    char name[MAX_NAME_LENGTH];
    printCentered("Enter Student Name to search: ", 50);
    cin.ignore();
    cin.getline(name, MAX_NAME_LENGTH);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, name) == 0) {
            cout << setw(25) << setfill(' ') << "ID: " << students[i].id << ", Name: " << students[i].name
                 << ", Age: " << students[i].age << ", Course: " << students[i].course << endl;
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Function to delete a student record by ID
void deleteStudent() {
    int id;
    printCentered("Enter Student ID to delete: ", 100);
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printCentered("Are you sure you want to delete this student record? (y/n): ", 100);
            char confirmation;
            cin >> confirmation;
            if (confirmation == 'y' || confirmation == 'Y') {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                printCentered("Student record deleted successfully.", 100);
            } else {
                printCentered("Deletion cancelled.", 100);
            }
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Function to update a student record by ID
void updateStudent() {
    int id;
    printCentered("Enter Student ID to update: ", 100);
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cin.ignore(); // to ignore the newline character left by cin

            printCentered("Enter new Student Name: ", 100);
            cin.getline(students[i].name, MAX_NAME_LENGTH);

            printCentered("Enter new Student Age: ", 100);
            cin >> students[i].age;
            while (cin.fail() || students[i].age <= 0 || students[i].age > 100) {
                cin.clear(); // Clear error flag
                cin.ignore(1000, '\n'); // Ignore the rest of the input
                printCentered("Invalid age. Please enter a valid age (1-100): ", 100);
                cin >> students[i].age;
            }
            cin.ignore();

            printCentered("Enter new Student Course: ", 100);
            cin.getline(students[i].course, MAX_COURSE_LENGTH);

            printCentered("Student record updated successfully.", 100);
            return;
        }
    }
    printCentered("Student record not found.", 100);
}

// Function to sort students by name
void sortStudentsByName() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printCentered("Students sorted by name.", 100);
}

// Function to display statistics
void displayStatistics() {
    if (studentCount == 0) {
        printCentered("No student records to calculate statistics.", 100);
        return;
    }
    int totalAge = 0;
    for (int i = 0; i < studentCount; i++) {
        totalAge += students[i].age;
    }
    cout << setw(25) << setfill(' ') << "Total number of students: " << studentCount << endl;
    cout << setw(25) << setfill(' ') << "Average age of students: " << static_cast<float>(totalAge) / studentCount << endl;
}

int main() {
    int choice;
    do {
        printCentered("-------- Student Management System Menu --------", 100);
        printCentered("1. Insert Student record", 100);
        printCentered("2. View All Student records", 100);
        printCentered("3. Search Student record by ID", 100);
        printCentered("4. Search Student record by Name", 100);
        printCentered("5. Delete Student record", 100);
        printCentered("6. Update Student record", 100);
        printCentered("7. Sort Students by Name", 100);
        printCentered("8. Display Statistics", 100);
        printCentered("9. Exit", 100);
        printCentered("--------------------------------------------", 100);
        printCentered("Enter your choice: ", 100);
        cin >> choice;

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchStudentByID();
                break;
            case 4:
                searchStudentByName();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                updateStudent();
                break;
            case 7:
                sortStudentsByName();
                break;
            case 8:
                displayStatistics();
                break;
            case 9:
                printCentered("Exiting the program.", 50);
                break;
            default:
                printCentered("Invalid choice. Please try again.", 50);
        }
    } while (choice != 9);

    return 0;
}
