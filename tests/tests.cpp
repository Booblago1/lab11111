#include "student_manager.h"
#include <cassert>
#include <iostream>
#include <cmath>

void run_tests() {
    StudentManager sm;

    sm.addStudent("Ivan", 19, 85);
    assert(sm.count() == 1);

    try { sm.addStudent("Ivan", 20, 90); assert(false); }
    catch (...) {}

    sm.addStudent("Anna", 18, 95);
    sm.addStudent("Petro", 21, 60);
    assert(sm.findBestStudent().name == "Anna");
    assert(sm.findWorstStudent().name == "Petro");

    double avg = sm.getAverageGrade();
    assert(std::fabs(avg - (85 + 95 + 60) / 3.0) < 1e-9);

    assert(sm.getGradeByName("Ivan") == 85);
    try { sm.getGradeByName("Mark"); assert(false); }
    catch (...) {}

    sm.removeStudent("Petro");
    assert(sm.count() == 2);

    try { sm.removeStudent("Petro"); assert(false); }
    catch (...) {}
    try { sm.addStudent("", 20, 90); assert(false); }
    catch (...) {}
    try { sm.addStudent("Oksana", 0, 80); assert(false); }
    catch (...) {}
    try { sm.addStudent("Dima", 19, 150); assert(false); }
    catch (...) {}

    sm.clear();
    assert(sm.count() == 0);

    std::cout << "All 15 tests passed successfully!" << std::endl;

}

int main() {
    run_tests();
    return 0;
}
//
