#include "People.h"
#include "Course.h"
#include "Cafeteria.h"
#include "Department.h"
#include "Library.h"
#include "Helpers.h"
#include "LoginManager.h"

#include <bits/stdc++.h>
#include <conio.h>


using namespace std;

//Filenames

const string studentFile = "student.csv";
const string facultyFile = "faculty.csv";
const string staffFile = "staff.csv";
const string courseFile = "course.csv";
const string courseStudentFile = "course_student.csv";
const string studentIDFile = "student_ids.txt";
const string facultyIDFile = "faculty_ids.txt";
const string staffIDFile = "staff_ids.txt";

//

Faculty F1("", "", "", 1, "", "", 1);
vector<Faculty> facultyList = F1.loadFromCSV(facultyFile);


Student st1("", "", 1, "", "", 1, 1, "");
vector<Student> studentList = st1.loadFromCSV(studentFile);

Course c1("", "", "", 0.00);
vector<Course> courseList = c1.loadFromCSV(courseFile);

vector<courseStudent> csvct =
{
    {"CSE 4301", "220041103", "A+"},
    {"CSE 4302", "220041103", "A+"},
    {"CSE 4303", "220041103", "B+"},
    {"CSE 4304", "220041103", "A+"},
    {"CSE 4305", "220041103", "N/A"},
    {"CSE 4306", "220041103", "N/A"},
    {"CSE 4307", "220041103", "N/A"}
};

std::string getMaskedInput()
{
    std::string password;
    char ch;
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b' && !password.empty())
        {
            password.pop_back();
            std::cout << "\b \b";
        }
        else if (ch != '\b')
        {
            password.push_back(ch);
            std::cout << "*";
        }
    }
    std::cout << std::endl;
    return password;
}
//change

int main()
{
    std::string id, password, role;
    std::cout << "\n========================================\n";
    std::cout << "              LOGIN PORTAL              \n";
    std::cout << "========================================\n";
    std::cout << "Select your role:\n1. Admin\n2. Student\n3. Faculty\nEnter your choice (1/2/3): ";
    std::cin >> role;
    std::cin.ignore();
    std::cout << "\n========================================\n";
    std::cout << "              USER LOGIN                \n";
    std::cout << "========================================\n";
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    password = getMaskedInput();
    if (role == "2")
    {
        if (id[0] == '2' && id[1] == '2')
        {
            studentLogin sl(id, studentList);
            sl.loginView();
        }
        else std::cout << "Invalid ID or Password for Student!\n";
    }
    else if (role == "3")
    {
        if (id[0] == '1' && id[1] == '1')
        {
            facultyLogin fl(id);
            fl.loginView();
        }
        else std::cout << "Invalid ID or Password for Faculty!\n";
    }
    else if (role == "1")
    {
        if (id == "admin" && password == "admin123")
        {
            std::cout << "Login successful for Admin\n";
        }
        else std::cout << "Invalid ID or Password for Admin!\n";
    }
    else
    {
        std::cout << "Invalid role selected!\n";
    }
    return 0;
}
//change
