#include "Course.h"
#include <fstream>
#include <sstream>
#include <map>

Course::Course(std::string courseID, std::string courseTitle, std::string FID, float credit)
{
    this->courseID = courseID;
    this->courseTitle = courseTitle;
    this->FID = FID;
    this->credit = credit;
}

void Course::saveToCSV(const std::string& fileName)
{
    std::ofstream file(fileName, std::ios::app);
    if (file.is_open())
    {
        file << courseID << "," << courseTitle << "," << FID << "," << credit << "\n";
        file.close();
    }
}

std::vector<Course> Course::loadFromCSV(const std::string& fileName)
{
    std::vector<Course> courses;
    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string courseID, courseTitle, FID;
            float credit;

            std::getline(ss, courseID, ',');
            std::getline(ss, courseTitle, ',');
            std::getline(ss, FID, ',');
            ss >> credit;

            courses.emplace_back(courseID, courseTitle, FID, credit);
        }
        file.close();
    }
    return courses;
}

/*
void Course::addCourse(std::string courseID, std::string courseTitle, std::string FID, float credit, const std::string& fileName){
    Course course(courseID, courseTitle, FID, credit, fileName);
    course.saveToCSV(fileName);
}
*/
void Course::displayCourse(std::vector<Faculty>& facultyList)
{
    std::string facultyName="N/A";
    for(auto& faculty:facultyList)
    {
        if(faculty.getFID() == FID)
        {
            facultyName = faculty.getFacultyName();
            break;
        }
    }
    std::cout << "Course Code: " << courseID
              << "\nCourse Title: " << courseTitle
              << "\nCourse Teacher: " << facultyName
              << "\nCredit: " << credit <<std::endl;

}

courseStudent::courseStudent(std::string courseID, std::string SID, std::string grade)
{
    this->courseID = courseID;
    this->SID = SID;
    this->grade = grade;
}

void courseStudent::saveToCSV(const std::string& fileName)
{
    std::ofstream file(fileName, std::ios::app);
    if (file.is_open())
    {
        file << courseID << "," << SID << "," << grade << "\n";
        file.close();
    }
}

std::vector<courseStudent> courseStudent::loadFromCSV(const std::string& fileName)
{
    std::vector<courseStudent> courseStudents;
    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string courseID, SID, grade;

            std::getline(ss, courseID, ',');
            std::getline(ss, SID, ',');
            std::getline(ss, grade, ',');

            courseStudents.emplace_back(courseID, SID, grade);
        }
        file.close();
    }
    return courseStudents;
}

std::vector<courseStudent> courseRecords =
{
    {
        "CSE 4301", "220041126", "A+"
    },
    {
        "CSE 4302", "220041126", "A+"
    }
};
