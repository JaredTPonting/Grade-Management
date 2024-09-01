#include "Student.h"

Student::Student(int id, std::string name) : id(id), name(name) {}

int Student::getId() const{
    return id;
}

std::string Student::getName() const{
    return name;
}

void Student::addGrade(float grade) {
    grades.push_back(grade);
}

float Student::getAverageGrade() const {
    float sum = 0;
    for (float grade : grades) {
        sum += grade;
    }
    return grades.empty() ? 0 : sum / grades.size();
}