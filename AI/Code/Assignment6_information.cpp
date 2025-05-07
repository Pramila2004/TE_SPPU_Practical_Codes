#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string branch;
    int age;
};

vector<Student> students;

void insertStudent() {
    Student s;
    cout << "\nEnter Student ID: ";
    cin >> s.id;
    cout << "Enter Name (no spaces): ";
    cin >> s.name;
    cout << "Enter Branch (no spaces): ";
    cin >> s.branch;
    cout << "Enter Age: ";
    cin >> s.age;

    students.push_back(s);
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n=== Student Records ===\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id << ", Name: " << s.name
             << ", Branch: " << s.branch << ", Age: " << s.age << "\n";
    }
}

void searchStudent() {
    string id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Record Found: ID=" << s.id << ", Name=" << s.name
                 << ", Branch=" << s.branch << ", Age=" << s.age << "\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

void updateStudent() {
    string id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    for (auto& s : students) {
        if (s.id == id) {
            cout << "Enter New Name (no spaces): ";
            cin >> s.name;
            cout << "Enter New Branch (no spaces): ";
            cin >> s.branch;
            cout << "Enter New Age: ";
            cin >> s.age;
            cout << "Student record updated.\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

void deleteStudent() {
    string id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student record deleted.\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n=== Student Management Menu ===\n";
        cout << "1. Insert Student\n2. Display Students\n3. Search Student\n";
        cout << "4. Update Student\n5. Delete Student\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
