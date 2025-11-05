#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

struct Student {
    std::string name;
    int age;
    double grade;
};

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string& name, int age, double grade);
    void removeStudent(const std::string& name);
    double getAverageGrade() const;
    Student findBestStudent() const;
    Student findWorstStudent() const;
    bool exists(const std::string& name) const;
    int count() const;
    void clear();
    double getGradeByName(const std::string& name) const;
};

#endif
#pragma once