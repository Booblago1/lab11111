#include "student_manager.h"

void StudentManager::addStudent(const std::string& name, int age, double grade) {
    if (name.empty()) throw std::invalid_argument("Порожнє ім’я");
    if (age <= 0) throw std::invalid_argument("Вік має бути позитивним");
    if (grade < 0 || grade > 100) throw std::invalid_argument("Оцінка має бути в діапазоні 0-100");
    if (exists(name)) throw std::invalid_argument("Студент уже існує");

    students.push_back({ name, age, grade });
}

void StudentManager::removeStudent(const std::string& name) {
    auto it = std::remove_if(students.begin(), students.end(),
        [&](const Student& s) { return s.name == name; });
    if (it == students.end()) throw std::invalid_argument("Студента не знайдено");
    students.erase(it, students.end());
}

double StudentManager::getAverageGrade() const {
    if (students.empty()) throw std::runtime_error("Список порожній");
    double sum = std::accumulate(students.begin(), students.end(), 0.0,
        [](double acc, const Student& s) { return acc + s.grade; });
    return sum / students.size();
}

Student StudentManager::findBestStudent() const {
    if (students.empty()) throw std::runtime_error("Список порожній");
    return *std::max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.grade < b.grade; });
}

Student StudentManager::findWorstStudent() const {
    if (students.empty()) throw std::runtime_error("Список порожній");
    return *std::min_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.grade < b.grade; });
}

bool StudentManager::exists(const std::string& name) const {
    return std::any_of(students.begin(), students.end(),
        [&](const Student& s) { return s.name == name; });
}

int StudentManager::count() const { return students.size(); }

void StudentManager::clear() { students.clear(); }

double StudentManager::getGradeByName(const std::string& name) const {
    for (auto& s : students)
        if (s.name == name) return s.grade;
    throw std::invalid_argument("Студента не знайдено");
}