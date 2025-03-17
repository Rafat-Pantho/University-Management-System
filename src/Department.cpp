#include "Department.h"

Department::Department(std::string deptName, std::vector<Student> students, std::vector<Faculty> faculty, std::vector<Staff> staff)
{
    this->deptName = deptName;
    this->students = students;
    this->faculty = faculty;
    this->staff = staff;
}

Department::~Department()
{
}

void Department::displayDepartment()
{
    std::cout << "Department Name: " << deptName << "\n";
    std::cout << "List of students:\n";
    std::vector<Student> studentList = getStudents();
    for(int i=0; i<studentList.size(); i++)
    {
        studentList[i].displayStudentInfo();
    }
    std::cout << "List of faculty members:\n";
    std::vector<Faculty> facultyList = getFaculty();
    for(int i=0; i<facultyList.size(); i++)
    {
        facultyList[i].displayFacultyInfo();
    }
    std::cout << "LIst of staff members:\n";
    std::vector<Staff> staffList = getStaff();
    for(int i=0; i<staffList.size(); i++)
    {
        staffList[i].displayStaffInfo();
    }
}
