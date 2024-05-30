#include <iostream>
#include <cstring>
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
        cout << "Student record list is full." << endl;
        return;
    }

    int id, age;
    char name[MAX_NAME_LENGTH], course[MAX_COURSE_LENGTH];

    cout << "Enter Student ID: ";
    cin >> id;
    while (!isUniqueID(id)) {
        cout << "ID already exists. Enter a unique Student ID: ";
        cin >> id;
    }
    students[studentCount].id = id;

    cin.ignore(); 

    cout << "Enter Student Name: ";
    cin.getline(students[studentCount].name, MAX_NAME_LENGTH);

    cout << "Enter Student Age: ";
    cin >> students[studentCount].age;
    while (cin.fail() || students[studentCount].age <= 0 || students[studentCount].age > 100) {
        cin.clear(); 
        cin.ignore(1000, '\n'); 
        cout << "Invalid age. Please enter a valid age (1-100): ";
        cin >> students[studentCount].age;
    }
    cin.ignore();

    cout << "Enter Student Course: ";
    cin.getline(students[studentCount].course, MAX_COURSE_LENGTH);

    studentCount++;
    cout << "Student record inserted successfully." << endl;
}

// Function to view all student records
void viewAllStudents() {
    if (studentCount == 0) {
        cout << "No student records found." << endl;
        return;
    }
    cout << "ID\tName\t\tAge\tCourse" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].id << "\t" << students[i].name << "\t\t" << students[i].age << "\t" << students[i].course << endl;
    }
}

// Function to search for a student record by ID
void searchStudentByID() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "ID: " << students[i].id << ", Name: " << students[i].name
                 << ", Age: " << students[i].age << ", Course: " << students[i].course << endl;
            return;
        }
    }
    cout << "Student record not found." << endl;
}

// Function to search for a student record by name
void searchStudentByName() {
    char name[MAX_NAME_LENGTH];
    cout << "Enter Student Name to search: ";
    cin.ignore();
    cin.getline(name, MAX_NAME_LENGTH);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, name) == 0) {
            cout << "ID: " << students[i].id << ", Name: " << students[i].name
                 << ", Age: " << students[i].age << ", Course: " << students[i].course << endl;
            return;
        }
    }
    cout << "Student record not found." << endl;
}

// Function to delete a student record by ID
void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Are you sure you want to delete this student record? (y/n): ";
            char confirmation;
            cin >> confirmation;
            if (confirmation == 'y' || confirmation == 'Y') {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "Student record deleted successfully." << endl;
            } else {
                cout << "Deletion cancelled." << endl;
            }
            return;
        }
    }
    cout << "Student record not found." << endl;
}

// Function to update a student record by ID
void updateStudent() {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cin.ignore(); // to ignore the newline character left by cin

            cout << "Enter new Student Name: ";
            cin.getline(students[i].name, MAX_NAME_LENGTH);

            cout << "Enter new Student Age: ";
            cin >> students[i].age;
            while (cin.fail() || students[i].age <= 0 || students[i].age > 100) {
                cin.clear(); // Clear error flag
                cin.ignore(1000, '\n'); // Ignore the rest of the input
                cout << "Invalid age. Please enter a valid age (1-100): ";
                cin >> students[i].age;
            }
            cin.ignore();

            cout << "Enter new Student Course: ";
            cin.getline(students[i].course, MAX_COURSE_LENGTH);

            cout << "Student record updated successfully." << endl;
            return;
        }
    }
    cout << "Student record not found." << endl;
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
    cout << "Students sorted by name." << endl;
}

// Function to display statistics
void displayStatistics() {
    if (studentCount == 0) {
        cout << "No student records to calculate statistics." << endl;
        return;
    }
    int totalAge = 0;
    for (int i = 0; i < studentCount; i++) {
        totalAge += students[i].age;
    }
    cout << "Total number of students: " << studentCount << endl;
    cout << "Average age of students: " << static_cast<float>(totalAge) / studentCount << endl;
}

int main() {
    int choice;
    do {
        cout << "\nStudent Management System Menu:" << endl;
        cout << "1. Insert Student record" << endl;
        cout << "2. View All Student records" << endl;
        cout << "3. Search Student record by ID" << endl;
        cout << "4. Search Student record by Name" << endl;
        cout << "5. Delete Student record" << endl;
        cout << "6. Update Student record" << endl;
        cout << "7. Sort Students by Name" << endl;
        cout << "8. Display Statistics" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
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
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
