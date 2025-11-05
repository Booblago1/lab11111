#include "student_manager.h"
#include <gtest/gtest.h>
#include <cmath>

// --- 1. Додавання студента ---
TEST(StudentManagerTest, AddStudentIncreasesCount) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    EXPECT_EQ(sm.count(), 1);
}

// --- 2. Додавання дубліката ---
TEST(StudentManagerTest, AddDuplicateThrows) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    EXPECT_THROW(sm.addStudent("Ivan", 20, 90), std::exception);
}

// --- 3-4. Додавання кількох студентів, пошук кращого та гіршого ---
TEST(StudentManagerTest, FindBestAndWorstStudent) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    sm.addStudent("Anna", 18, 95);
    sm.addStudent("Petro", 21, 60);
    EXPECT_EQ(sm.findBestStudent().name, "Anna");
    EXPECT_EQ(sm.findWorstStudent().name, "Petro");
}

// --- 5. Середній бал ---
TEST(StudentManagerTest, AverageGradeIsCorrect) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    sm.addStudent("Anna", 18, 95);
    sm.addStudent("Petro", 21, 60);
    double expected = (85 + 95 + 60) / 3.0;
    EXPECT_NEAR(sm.getAverageGrade(), expected, 1e-9);
}

// --- 6-7. Отримання оцінки за ім’ям ---
TEST(StudentManagerTest, GetGradeByNameWorks) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    EXPECT_EQ(sm.getGradeByName("Ivan"), 85);
}

TEST(StudentManagerTest, GetGradeByNameThrowsForMissing) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    EXPECT_THROW(sm.getGradeByName("Mark"), std::exception);
}

// --- 8-9. Видалення студента ---
TEST(StudentManagerTest, RemoveStudentDecreasesCount) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    sm.addStudent("Anna", 18, 95);
    sm.removeStudent("Ivan");
    EXPECT_EQ(sm.count(), 1);
}

TEST(StudentManagerTest, RemoveMissingStudentThrows) {
    StudentManager sm;
    sm.addStudent("Anna", 18, 95);
    EXPECT_THROW(sm.removeStudent("Petro"), std::exception);
}

// --- 10-12. Некоректні дані ---
TEST(StudentManagerTest, AddInvalidNameThrows) {
    StudentManager sm;
    EXPECT_THROW(sm.addStudent("", 20, 90), std::exception);
}

TEST(StudentManagerTest, AddInvalidAgeThrows) {
    StudentManager sm;
    EXPECT_THROW(sm.addStudent("Oksana", 0, 80), std::exception);
}

TEST(StudentManagerTest, AddInvalidGradeThrows) {
    StudentManager sm;
    EXPECT_THROW(sm.addStudent("Dima", 19, 150), std::exception);
}

// --- 13. Очищення ---
TEST(StudentManagerTest, ClearEmptiesList) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    sm.clear();
    EXPECT_EQ(sm.count(), 0);
}

// --- 14. Перевірка підрахунку ---
TEST(StudentManagerTest, CountReturnsCorrectValue) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    sm.addStudent("Anna", 18, 95);
    EXPECT_EQ(sm.count(), 2);
}

// --- 15. Перевірка стабільності ---
TEST(StudentManagerTest, StabilityAfterMultipleOps) {
    StudentManager sm;
    sm.addStudent("Ivan", 19, 85);
    sm.addStudent("Anna", 18, 95);
    sm.removeStudent("Ivan");
    sm.addStudent("Petro", 22, 70);
    EXPECT_EQ(sm.findBestStudent().name, "Anna");
    EXPECT_NEAR(sm.getAverageGrade(), (95 + 70) / 2.0, 1e-9);
}

// --- Точка входу ---
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/