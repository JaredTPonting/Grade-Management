#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
    private:
        int id;
        std::string name;
        std::vector<float> grades;

    public:
        Student(int id, std::string name);

        int getId() const;
        std::string getName() const;
        void addGrade(float grade);
        float getAverageGrade() const;
        void setName(std::string newName);
};

#endif // !STUDENT_H