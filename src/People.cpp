#include "People.h"

People::People(std::string name, std::string address, int age)
{
    this->name = name;
    this->address = address;
    this->age = age;
}

People::~People() {}

// Student CSV Functions
Student::Student(std::string name, std::string address, int age, std::string dept, std::string SID, int semester, float cgpa, std::string degreeType):People(name, address, age)
{
    this->dept = dept;
    this->SID = SID;
    this->semester = semester;
    this->cgpa = cgpa;
    this->degreeType = degreeType;
}


void Student::saveToCSV(const std::string& filename)
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        // Writing the fields to the file with proper quoting
        file << "\"" << name << "\",\"" << address << "\"," << age << ",\""
             << dept << "\",\"" << SID << "\"," << semester << ","
             << cgpa << ",\"" << degreeType << "\"\n";
        file.close();
    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
}


std::vector<Student> Student::loadFromCSV(const std::string& filename)
{
    std::vector<Student> studentList;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return studentList;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name, address, dept, SID, degreeType, ageStr, semesterStr, cgpaStr;
        int age, semester;
        float cgpa;

        // Function to read fields while handling quotes
        auto getField = [](std::stringstream& ss)
        {
            std::string field;
            if (ss.peek() == '"')    // Handle quoted fields
            {
                ss.get(); // Remove leading quote
                std::getline(ss, field, '"'); // Read until closing quote
                ss.get(); // Consume the following comma
            }
            else
            {
                std::getline(ss, field, ','); // Read normally if not quoted
            }
            return field;
        };

        // Extract fields
        name = getField(ss);
        address = getField(ss);
        ageStr = getField(ss);
        dept = getField(ss);
        SID = getField(ss);
        semesterStr = getField(ss);
        cgpaStr = getField(ss);
        degreeType = getField(ss);

        // Convert numeric values safely
        try
        {
            age = std::stoi(ageStr);
            semester = std::stoi(semesterStr);
            cgpa = std::stof(cgpaStr);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error parsing CSV line: " << line << " (" << e.what() << ")\n";
            continue; // Skip this malformed entry
        }

        // Add to the student list
        studentList.emplace_back(name, address, age, dept, SID, semester, cgpa, degreeType);
    }

    file.close();
    return studentList;
}


void Student::displayStudentInfo()
{
    std::cout << "Name: " << name << "\n"
              << "Status: " << "Student\n"
              << "ID: " << SID << "\n"
              << "CGPA: " << cgpa << std::endl;
}

void Student::alterStudent(const std::string& filename, const std::string& newName, const std::string& newAddress, int newAge, const std::string& newDept, const std::string& newSID, int newSemester, float newCgpa, const std::string& newDegreeType)
{
    std::vector<Student> students = loadFromCSV(filename);
    bool found = false;

    for (Student& student : students)
    {
        if (student.getSID() == SID)   // Match student by SID
        {
            student.Setname(newName);
            student.Setaddress(newAddress);
            student.Setage(newAge);
            student.setDept(newDept);
            student.setSID(newSID);
            student.setSemester(newSemester);
            student.setCgpa(newCgpa);
            student.setDegreeType(newDegreeType);
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Student with SID " << SID << " not found." << std::endl;
        return;
    }

    // Write back to file
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Error opening file " << filename << " for writing." << std::endl;
        return;
    }

    for (Student& student : students)
    {
        outFile << student.Getname() << ","
                << student.Getaddress() << ","
                << student.Getage() << ","
                << student.getDept() << ","
                << student.getSID() << ","
                << student.getSemester() << ","
                << student.getCgpa() << ","
                << student.getDegreeType() << "\n";
    }

    outFile.close();
    std::cout << "Student record updated successfully." << std::endl;
}

Student::~Student() {}

// Faculty CSV Functions
Faculty::Faculty(std::string FID, std::string name, std::string address, int age, std::string post, std::string dept, float salary):People(name, address, age)
{
    this->FID = FID;
    this->post = post;
    this->dept = dept;
    this->salary = salary;
}

void Faculty::saveToCSV(const std::string& filename)
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        // Writing the fields to the file without credits
        file << "\"" << FID << "\",\"" << name << "\",\"" << address << "\","
             << age << ",\"" << post << "\",\"" << dept << "\","
             << salary << "\n";  // Removed credits
        file.close();
    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
}

std::vector<Faculty> Faculty::loadFromCSV(const std::string& filename)
{
    std::vector<Faculty> facultyList;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return facultyList;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string FID, name, address, post, dept, ageStr, salaryStr;
        int age;
        float salary;

        // Function to read fields while handling quotes
        auto getField = [](std::stringstream& ss)
        {
            std::string field;
            if (ss.peek() == '"')    // Handle quoted fields
            {
                ss.get(); // Remove leading quote
                std::getline(ss, field, '"'); // Read until closing quote
                ss.get(); // Consume the following comma
            }
            else
            {
                std::getline(ss, field, ','); // Read normally if not quoted
            }
            return field;
        };

        // Extract fields
        FID = getField(ss);
        name = getField(ss);
        address = getField(ss);
        ageStr = getField(ss);
        post = getField(ss);
        dept = getField(ss);
        salaryStr = getField(ss); // Removed credits

        // Convert numeric values safely
        try
        {
            age = std::stoi(ageStr);
            salary = std::stof(salaryStr); // Handle salary conversion
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error parsing CSV line: " << line << " (" << e.what() << ")\n";
            continue; // Skip this malformed entry
        }

        // Add to the faculty list
        facultyList.emplace_back(FID, name, address, age, post, dept, salary); // Removed credits
    }

    file.close();
    return facultyList;
}


void Faculty::displayFacultyInfo()
{
    std::cout << "\n==================================\n";
    std::cout << "         FACULTY DETAILS\n";
    std::cout << "==================================\n";
    std::cout << " Name     : " << name << "\n";
    std::cout << " Status   : Faculty\n";
    std::cout << " Post     : " << post << "\n";
    std::cout << " Salary   : TK. " << salary << "\n";
    std::cout << " Address  : " << address << "\n";
    std::cout << "==================================\n";
}

Faculty::~Faculty() {}
// Staff CSV Functions
Staff::Staff(std::string name, std::string address, int age, std::string post, float salary):People(name, address, age)
{
    this->post = post;
    this->salary = salary;
}

void Staff::saveToCSV(const std::string& filename)
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open())
    {
        // Writing the fields to the file with proper quoting
        file << "\"" << name << "\",\"" << address << "\"," << age << ",\""
             << post << "\"," << salary << "\n";
        file.close();
    }
    else
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
}

std::vector<Staff> Staff::loadFromCSV(const std::string& filename)
{
    std::vector<Staff> staffList;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return staffList;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name, address, post, ageStr, salaryStr;
        int age;
        float salary;

        // Function to read fields while handling quotes
        auto getField = [](std::stringstream& ss)
        {
            std::string field;
            if (ss.peek() == '"')    // Handle quoted fields
            {
                ss.get(); // Remove leading quote
                std::getline(ss, field, '"'); // Read until closing quote
                ss.get(); // Consume the following comma
            }
            else
            {
                std::getline(ss, field, ','); // Read normally if not quoted
            }
            return field;
        };

        // Extract fields
        name = getField(ss);
        address = getField(ss);
        ageStr = getField(ss);
        post = getField(ss);
        salaryStr = getField(ss);

        // Convert numeric values safely
        try
        {
            age = std::stoi(ageStr);
            salary = std::stof(salaryStr);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error parsing CSV line: " << line << " (" << e.what() << ")\n";
            continue; // Skip this malformed entry
        }

        // Add to the staff list
        staffList.emplace_back(name, address, age, post, salary);
    }

    file.close();
    return staffList;
}

void Staff::displayStaffInfo()
{
    std::cout << "Name: " << name << "\n"
              << "Post: " << post << "\n"
              << "Salary: " << salary << std::endl;
}
Staff::~Staff() {}
