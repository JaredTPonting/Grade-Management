#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include "Student.h"
#include <vector>

class GradeManager {
    private:
        std::vector<Student> students;

    public:
        void addStudent(const Student& student);
        void updateStudent(int studentId);
        void displayStudent(int studentId) const;
        void saveToFile(const std::string& filename) const;
        void loadfromFile(const std::string& filename);
};

#endif // !GRADEMANAGER_H