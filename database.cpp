#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Class to represent a Student
class Student {
public:
    int id;
    string name;
    int age;
    string course;

    Student(int id, string name, int age, string course) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->course = course;
    }

    void display() const {
        cout << "ID: " << id << "\n"
             << "Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Course: " << course << "\n";
    }
};

// Class for managing the Student Database
class StudentDatabase {
private:
    vector<Student> students;

public:
    // Add a new student
    void addStudent(int id, string name, int age, string course) {
        // Check if student ID already exists
        auto it = find_if(students.begin(), students.end(),
                          [id](const Student& s) { return s.id == id; });
        if (it != students.end()) {
            cout << "Student with ID " << id << " already exists!\n";
            return;
        }

        students.emplace_back(id, name, age, course);
        cout << "Student added successfully!\n";
    }

    // Display all students
    void displayStudents() const {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\n--- Student Records ---\n";
        for (const auto& student : students) {
            student.display();
            cout << "-----------------------\n";
        }
    }

    // Search for a student by ID
    void searchStudent(int id) const {
        auto it = find_if(students.begin(), students.end(),
                          [id](const Student& s) { return s.id == id; });
        if (it != students.end()) {
            cout << "Student found:\n";
            it->display();
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    // Update student details
    void updateStudent(int id) {
        auto it = find_if(students.begin(), students.end(),
                          [id](Student& s) { return s.id == id; });
        if (it != students.end()) {
            cout << "Enter new name (current: " << it->name << "): ";
            cin >> it->name;
            cout << "Enter new age (current: " << it->age << "): ";
            cin >> it->age;
            cout << "Enter new course (current: " << it->course << "): ";
            cin >> it->course;
            cout << "Student record updated successfully!\n";
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    // Delete a student by ID
    void deleteStudent(int id) {
        auto it = remove_if(students.begin(), students.end(),
                            [id](const Student& s) { return s.id == id; });
        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student with ID " << id << " deleted successfully!\n";
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }
};

int main() {
    StudentDatabase db;
    int choice;

    do {
        cout << "\n--- Student Database Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, age;
            string name, course;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> name;
            cout << "Enter Student Age: ";
            cin >> age;
            cout << "Enter Course: ";
            cin >> course;
            db.addStudent(id, name, age, course);
            break;
        }
        case 2:
            db.displayStudents();
            break;
        case 3: {
            int id;
            cout << "Enter Student ID to search: ";
            cin >> id;
            db.searchStudent(id);
            break;
        }
        case 4: {
            int id;
            cout << "Enter Student ID to update: ";
            cin >> id;
            db.updateStudent(id);
            break;
        }
        case 5: {
            int id;
            cout << "Enter Student ID to delete: ";
            cin >> id;
            db.deleteStudent(id);
            break;
        }
        case 6:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
