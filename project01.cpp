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

int main() {
    return 0;
}