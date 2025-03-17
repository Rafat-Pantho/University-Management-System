#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>



class People {
protected:
    std::string name;
    std::string address;
    int age;
public:
    People(std::string name, std::string address, int age);
    ~People();

    std::string Getname() { return name; }
    void Setname(std::string val) { name = val; }
    std::string Getaddress() { return address; }
    void Setaddress(std::string val) { address = val; }
    int Getage() { return age; }
    void Setage(int val) { age = val; }
};

class Student : public People {
private:
    std::string dept;
    std::string SID;
    int semester;

    float cgpa;
    std::string degreeType;

public:

    Student(std::string name, std::string address, int age, std::string dept, std::string SID, int semester, float cgpa, std::string degreeType);

    ~Student();

    void displayStudentInfo();

    void saveToCSV(const std::string& filename);
    static std::vector<Student> loadFromCSV(const std::string& filename);

    std::string getDept() const { return dept; }
    std::string getSID() const { return SID; }
    int getSemester() const { return semester; }
    float getCgpa() const { return cgpa; }
    std::string getDegreeType() const { return degreeType; }

    void setDept(const std::string& newDept) { dept = newDept; }
    void setSID(const std::string& newSID) { SID = newSID; }
    void setSemester(int newSemester) { semester = newSemester; }
    void setCgpa(float newCgpa) { cgpa = newCgpa; }
    void setDegreeType(std::string newDegreeType) { degreeType = newDegreeType; }

    void alterStudent(const std::string& filename, const std::string& newName, const std::string& newAddress, int newAge, const std::string& newDept, const std::string& newSID, int newSemester, float newCgpa, const std::string& newDegreeType);
};


class Faculty : public People {
private:
    std::string FID;
    std::string post;
    std::string dept;

    float salary;

public:
    Faculty(std::string FID, std::string name, std::string address, int age,
            std::string post, std::string dept, float salary);
    ~Faculty();

    void displayFacultyInfo();
    void saveToCSV(const std::string& filename);
    static std::vector<Faculty> loadFromCSV(const std::string& filename);

    std::string getFID() const { return FID; }
    std::string getPost() const { return post; }
    std::string getDept() const { return dept; }
    float getSalary() const { return salary; }
    std::string getFacultyName(){return name;}

    void setFID(const std::string& val) { FID = val; }
    void setPost(const std::string& val) { post = val; }
    void setDept(const std::string& val) { dept = val; }
    void setSalary(float val) { salary = val; }
};


class Staff : protected People {
private:
    std::string post;
    float salary;

public:
    Staff(std::string name, std::string address, int age, std::string post, float salary);
    ~Staff();

    void displayStaffInfo();
    void saveToCSV(const std::string& filename);
    static std::vector<Staff> loadFromCSV(const std::string& filename);

    std::string getPost() const { return post; }
    float getSalary() const { return salary; }

    void setPost(const std::string& val) { post = val; }
    void setSalary(float val) { salary = val; }
};

#endif // PEOPLE_H
