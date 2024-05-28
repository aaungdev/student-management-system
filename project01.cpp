#include <iostream>
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

// Function to insert a new student record
void insertStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student record list is full." << endl;
        return;
    }

    cout << "Enter Student ID: ";
    cin >> students[studentCount].id;
    cin.ignore(); // to ignore the newline character left by cin

    cout << "Enter Student Name: ";
    cin.getline(students[studentCount].name, MAX_NAME_LENGTH);

    cout << "Enter Student Age: ";
    cin >> students[studentCount].age;
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
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name
             << ", Age: " << students[i].age << ", Course: " << students[i].course << endl;
    }
}

// Function to search for a student record by ID
void searchStudent() {
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

// Function to delete a student record by ID
void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student record deleted successfully." << endl;
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
            cin.ignore();

            cout << "Enter new Student Course: ";
            cin.getline(students[i].course, MAX_COURSE_LENGTH);

            cout << "Student record updated successfully." << endl;
            return;
        }
    }
    cout << "Student record not found." << endl;
}

int main() {
    int choice;
    do {
        cout << "Student Management System Menu:" << endl;
        cout << "1. Insert Student record" << endl;
        cout << "2. View All Student records" << endl;
        cout << "3. Search Student record" << endl;
        cout << "4. Delete Student record" << endl;
        cout << "5. Update Student record" << endl;
        cout << "6. Exit" << endl;
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
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                updateStudent();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
