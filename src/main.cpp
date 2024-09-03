#include "GradeManager.h"
#include <iostream>
#include <limits>

void add_student(GradeManager& funcGradeManager) {
    std::string studentName;
    std::cout << "Enter New Student name: " << std::endl;
    std::getline(std::cin, studentName);

    int studentID;
    std::cout << "Enter New Student ID: " << std::endl;
    std::cin >> studentID;

    Student newStudent(studentID, studentName);
    funcGradeManager.addStudent(newStudent);
}

void update_student(GradeManager& funcGradeManager) {
    int studentID;
    std::cout << "Enter Student ID: " << std::endl;
    std::cin >> studentID;

    funcGradeManager.updateStudent(studentID);
}

void display_student(GradeManager& funcGradeManager) {
    int studentID;
    std::cout << "Enter Student ID: " << std::endl;
    std::cin >> studentID;

    funcGradeManager.displayStudent(studentID);
}

int main() {
    GradeManager manager;
    manager.loadfromFile("data/students.txt");

    int choice;
    do {
        std::cout << "1. Add Student\n2. Update Student\n3. Display Student\n4. Load Students\n5. Save and Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                add_student(manager);
                break;
            case 2:
                update_student(manager);
                break;
            case 3:
                display_student(manager);
                break;
            case 4:
                manager.loadfromFile("data/students.txt");
                break;
            case 5:
                manager.saveToFile("data/students.txt");
                std::cout << "Data saved. Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
