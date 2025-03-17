#ifndef COURSE_H
#define COURSE_H

#include "People.h"

#include <iostream>
#include <string>
#include <vector>

class Course{
private:
    std::string courseID;
    std::string courseTitle;
    std::string FID;
    float credit;
public:
    Course(std::string courseID, std::string courseTitle, std::string FID, float credit);

    std::string getcourseID(){return courseID;}
    void setcourseID(std::string val){courseID = val;}

    std::string getcourseTitle(){return courseTitle;}
    void setcourseTitle(std::string val){courseTitle = val;}

    std::string getFID(){return FID;}
    void setFID(std::string val){FID = val;}

    float getCredit(){return credit;}
    void setCredit(float val){credit = val;}

    void saveToCSV(const std::string& fileName);
    static std::vector<Course> loadFromCSV(const std::string& fileName);

    void displayCourse(std::vector<Faculty>& facultyList);
};


class courseStudent{
private:
    std::string courseID;
    std::string SID;
    std::string grade;
public:
    courseStudent(std::string courseID, std::string SID, std::string grade);

    std::string getcourseID(){return courseID;}
    void setcourseID(std::string val){courseID = val;}

    std::string getSID(){return SID;}
    void setSID(std::string val){SID = val;}

    std::string getGrade(){return grade;}
    void setGrade(std::string val){grade = val;}

    void saveToCSV(const std::string& fileName);
    static std::vector<courseStudent> loadFromCSV(const std::string& fileName);

    //void calculateGPA(std::string SID, std::vector<courseStudent> courseStudentList);
};

#endif // COURSE_H
