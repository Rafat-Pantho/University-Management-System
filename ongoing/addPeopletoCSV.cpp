#include "People.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void saveStudentsToCSV(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << "Name,Address,Age,Department,StudentID,Semester,Credit,CGPA\n";
        for (const auto& student : students) {
            file << student.getName() << ","
                 << student.getAddress() << ","
                 << student.getAge() << ","
                 << student.getDept() << ","
                 << student.getID() << ","
                 << student.getSemester() << ","
                 << student.getCredit() << ","
                 << student.getCGPA() << "\n";
        }
        file.close();
    }
}

void saveFacultyToCSV(const std::vector<Faculty>& faculty, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << "Name,Address,Age,Post,Department,Credits,Salary\n";
        for (const auto& f : faculty) {
            file << f.getName() << ","
                 << f.getAddress() << ","
                 << f.getAge() << ","
                 << f.getPost() << ","
                 << f.getDept() << ","
                 << f.getCredits() << ","
                 << f.getSalary() << "\n";
        }
        file.close();
    }
}

void saveStaffToCSV(const std::vector<Staff>& staff, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << "Name,Address,Age,Post,Salary\n";
        for (const auto& s : staff) {
            file << s.getName() << ","
                 << s.getAddress() << ","
                 << s.getAge() << ","
                 << s.getPost() << ","
                 << s.getSalary() << "\n";
        }
        file.close();
    }
}

void FacultyList::addFaculty(Faculty F) {
    faculty.push_back(F);
    saveFacultyToCSV(faculty, "faculty.csv");
}

void FacultyList::deleteFaculty(std::string name) {
    int ind = -1;
    for (int i = 0; i < faculty.size(); i++) {
        if (faculty[i].getName() == name) {
            ind = i;
            break;
        }
    }
    if (ind >= 0) {
        faculty.erase(faculty.begin() + ind);
        saveFacultyToCSV(faculty, "faculty.csv");
    }
}

void FacultyList::alterFaculty(std::string name, Faculty f) {
    int ind = -1;
    for (int i = 0; i < faculty.size(); i++) {
        if (faculty[i].getName() == name) {
            ind = i;
            break;
        }
    }
    if (ind >= 0) {
        faculty[ind] = f;
        saveFacultyToCSV(faculty, "faculty.csv");
    }
}

void StaffList::addStaff(Staff S) {
    staff.push_back(S);
    saveStaffToCSV(staff, "staff.csv");
}

void StaffList::deleteStaff(std::string name) {
    int ind = -1;
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getName() == name) {
            ind = i;
            break;
        }
    }
    if (ind >= 0) {
        staff.erase(staff.begin() + ind);
        saveStaffToCSV(staff, "staff.csv");
    }
}

void StaffList::alterStaff(std::string name, Staff s) {
    int ind = -1;
    for (int i = 0; i < staff.size(); i++) {
        if (staff[i].getName() == name) {
            ind = i;
            break;
        }
    }
    if (ind >= 0) {
        staff[ind] = s;
        saveStaffToCSV(staff, "staff.csv");
    }
}
