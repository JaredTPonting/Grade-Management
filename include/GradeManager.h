#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include "Student.h"
#include <vector>

class GradeManager {
    private:
        std::vector<Student> students;

    public:
        void addStudent(const Student& student);
        Student* getStudent(int studentId);
        void updateStudent(int studentId);
        void displayStudent(int studentId);
        void saveToFile(const std::string& filename);
        void loadfromFile(const std::string& filename);
};

#endif // !GRADEMANAGER_H