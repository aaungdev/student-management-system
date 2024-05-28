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

int main() {
    return 0;
}