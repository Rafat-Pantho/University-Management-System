#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#include "Cafeteria.h"
#include "Course.h"
#include "Department.h"
#include "Library.h"
#include "People.h"


#include <map>
#include <iomanip>
//Functions for student class
Student* findStudent(const std::string& sid, std::vector<Student>& st_vc);
void displayStudentDetails(std::string& sid, std::vector<Student> studentList);
void orderStudentByRes(std::vector<Student>& st_vc);
std::vector<std::string> getStudentIdList(const std::string& fileName);
void displayAllStudents(std::vector<Student>& st_vc);
void addStudent(const std::string& fileName);
void deleteStudent(const std::string& fileName, const std::string& studentID, std::vector<Student> studentList);
void alterStudent(const std::string& fileName, const std::string& studentID, std::vector<Student> studentList);
void getDetailedReport(std::string studentID, std::vector<courseStudent> courseStudentList, std::vector<Student> studentList);
void displayCurrentCourses(std::string studentID, std::vector<courseStudent> courseStudentList, std::vector<Student> studentList);

//Functions for faculty class
Faculty* findFaculty(const std::string& sid, std::vector<Faculty>& fc_vc);
void displayFacultyDetails(std::string& FID, std::vector<Faculty> facultyList);
std::vector<Faculty> findFacultyByName(const std::string& name, std::vector<Faculty>& fc_vc);
std::vector<Faculty> filterFacultyByPost(std::vector<Faculty>& fc_vc, std::string post);
std::vector<std::string> getFacultyIdList(const std::string& fileName);
void displayAllFaculty(std::vector<Faculty>& ft_vc);
void addFaculty(const std::string& fileName);
void deleteFaculty(const std::string& fileName, const std::string& facultyID, std::vector<Faculty> facultyList);
void alterFaculty(const std::string& fileName, const std::string& facultyID, std::vector<Faculty> facultyList);
void coursesTakenByFaculty(std::string& FID, std::vector<Course> courseList);

//Functions for course / courseStudent class
void calculateGPA(std::string SID, std::vector<courseStudent> courseStudentList);
void addCourse(std::string courseID, std::string courseTitle, std::string FID, float credit, const std::string& fileName);
Course* findCourse(std::string courseID, std::vector<Course> courseList);
void enrollStudent(std::string studentID, std::string courseID, std::vector<Course> courseList, std::vector<Student> studentList, const std::string& fileName);

//Library Functions
void displayInventory();
void displayBorrowedBooks();
void displayArchivedBooks();
void personBorrowBook(std::string& id);
void personReturnBook();
void viewBorrowedBooks(std::string& id);

//Cafeteria Functions
void cafeteria();

//Library Functions

void findBook(std::string& isbn);
void viewBorrowedBooks(std::string& id);
//void addBookToLibrary();

#endif // HELPERS_H_INCLUDED
