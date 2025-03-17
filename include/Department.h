#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "People.h"
#include <vector>

class Department
{
    private:
        std::string deptName;
        std::vector<Student> students;
        std::vector<Faculty> faculty;
        std::vector<Staff> staff;
    public:
        Department(std::string deptName,std::vector<Student> students, std::vector<Faculty> faculty, std::vector<Staff> staff);
        ~Department();

        std::vector<Student> getStudents(){return students;}
        void setStudents(std::vector<Student> val){students = val;}

        std::vector<Faculty> getFaculty(){return faculty;}
        void setFaculty(std::vector<Faculty> val){faculty = val;}

        std::vector<Staff> getStaff(){return staff;}
        void setStaff(std::vector<Staff> val){staff = val;}

        void displayDepartment();
};

#endif // DEPARTMENT_H
