#include "GradeManager.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>


void GradeManager::addStudent(const Student& student) {
    students.push_back(student);
    std::cout << "Student Added Successfully.\n" << std::endl;
};

Student* GradeManager::getStudent(int studentId) {
    auto it = std::find_if(students.begin(), students.end(),
        [studentId](const Student& student) {
            return student.getId() == studentId;
        }
    );

    if (it != students.end()) {
        return &(*it); // return pointer to found student object
    }
    else {
        return nullptr;
    }
}

void GradeManager::updateStudent(int studentId) {
    Student* student = getStudent(studentId);

    if (student != nullptr) {
        std::cout << "Would you like to add a new name for the student? (y/n)" << std::endl;
        char changeName;
        std::cin >> changeName;

        if (changeName == 'y' || changeName == 'Y') {
            std::cout << "Enter new name: " << std::endl;
            std::string newName;
            std::cin.ignore();
            std::getline(std::cin, newName);
            student->setName(newName);
        }

        char addGrade;
        std::cout << "Would you like to add a new grade? " << std::endl;
        std::cin >> addGrade;

        if (addGrade == 'y' || addGrade == 'Y') {
            std::cout << "Enter new grade: " << std::endl;
            float newGrade;
            std::cin >> newGrade;
            student->addGrade(newGrade);
        }
        std::cout << "Student updated successfully!" << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }
};

void GradeManager::displayStudent(int studentId) {
    Student* student = getStudent(studentId);

    if (student != nullptr) {
        std::cout << "Student ID: " << student->getId() << std::endl;
        std::cout << "Student Name: " << student-> getName() << std::endl;
        std::cout << "Grades: ";
        const std::vector<float>& grades = student->getGrades();
        for (float grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << "Average Grade: " << student->getAverageGrade() << std::endl;
    } else {
        std::cout << "Student not found!" << std::endl;
    }
}

void GradeManager::saveToFile(const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cout << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const Student& student : students) {
        outFile << student.getId() << std::endl;
        outFile << student.getName() << std::endl;
        outFile << student.getGrades().size() << std::endl;
        for (float grade : student.getGrades()) {
            outFile << grade << " ";
        }
        outFile << std::endl;
    }

    outFile.close();
    std::cout << "Data saved to " << filename << "successfully!" << std::endl;
}

void GradeManager::loadfromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "File not found: " << filename << std::endl;

        std::ofstream outFile(filename);
        if (outFile) {
            std::cerr << "File created: " << filename << std::endl;
        } else {
            std::cerr << "Error creating file: " << filename << std::endl;
            return;
        }
        outFile.close();
        return;
    }

    students.clear(); // clear current student list

    while (inFile) {
        int id;
        std::string name;
        size_t gradeCount;
        std::vector<float> grades;
        inFile >> id;
        inFile.ignore(); // ignore newline after ID
        std::getline(inFile, name);
        inFile >> gradeCount;

        grades.resize(gradeCount);
        for (size_t i=0; i < gradeCount; i++) {
            inFile >> grades[i];
        }

        if (inFile) {
            Student student(id, name);
            for (float grade: grades){
                student.addGrade(grade);
            }
            students.push_back(student);
        }
    }
}