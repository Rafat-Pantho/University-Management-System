#include "Helpers.h"


Student* findStudent(const std::string& sid, std::vector<Student>& st_vc)
{
    for (auto& student : st_vc)
    {
        if (student.getSID() == sid)
        {
            return &student;
        }
    }
    return nullptr;
}

void displayStudentDetails(std::string& sid, std::vector<Student> studentList)
{
    bool found = false;
    for (auto& student : studentList)
    {
        if (student.getSID() == sid)
        {
            std::cout << "\n==================================\n";
            std::cout << "       STUDENT DETAILS\n";
            std::cout << "==================================\n";
            std::cout << " Name       : " << student.Getname() << "\n";
            std::cout << " ID         : " << student.getSID() << "\n";
            std::cout << " Semester   : " << student.getSemester() << "\n";
            std::cout << " CGPA       : " << student.getCgpa() << "\n";
            std::cout << "==================================\n\n";
            found = true;
            break; // Assuming only one student has a given ID
        }
    }
    if (!found)
    {
        std::cout << "Student with ID " << sid << " not found!\n";
    }
}




void orderStudentByRes(std::vector<Student>& st_vc)
{
    std::vector<Student> new_vector = st_vc;
    std::sort(new_vector.begin(), new_vector.end(), [](const Student& a, const Student& b)
    {
        return a.getCgpa() > b.getCgpa();
    });
    for(auto it:new_vector)
    {
        it.displayStudentInfo();
        std::cout << std::endl;
    }
}

std::vector<std::string> getStudentIdList(const std::string& fileName)
{
    std::vector<std::string> sid_list;
    std::ifstream inputFile(fileName);
    if(!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return sid_list;
    }
    std::string id;
    while(std::getline(inputFile, id))
    {
        sid_list.push_back(id);
    }
    inputFile.close();
    return sid_list;
}

void displayAllStudents(std::vector<Student>& st_vc)
{
    if (st_vc.empty())
    {
        std::cout << "No students available.\n";
        return;
    }

    std::cout << "\n========================================\n";
    std::cout << "          ALL STUDENT DETAILS\n";
    std::cout << "========================================\n";

    for (auto& student : st_vc)
    {
        std::cout << " Name       : " << student.Getname() << "\n";
        std::cout << " ID         : " << student.getSID() << "\n";
        std::cout << " Semester   : " << student.getSemester() << "\n";
        std::cout << " CGPA       : " << student.getCgpa() << "\n";
        std::cout << "----------------------------------------\n";
    }
}


void addStudent(const std::string& fileName)
{
    std::string name, address, dept, sid, degree;
    int semester = 1, age;
    float cgpa = 0.0;

    std::cout << "\n========================================\n";
    std::cout << "         ADD NEW STUDENT\n";
    std::cout << "========================================\n";

    std::cout << "Enter New Student Name      : ";
    std::getline(std::cin >> std::ws, name); // Ensures leading whitespace is ignored

    std::cout << "Enter New Student Address   : ";
    std::getline(std::cin, address);

    std::cout << "Enter New Student Age       : ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears input buffer

    std::cout << "Enter New Student Department: ";
    std::getline(std::cin, dept);

    std::cout << "Enter New Student ID        : ";
    std::getline(std::cin, sid);

    std::cout << "Enter New Student Degree    : ";
    std::getline(std::cin, degree);

    std::cout << "========================================\n";

    Student student(name, address, age, dept, sid, semester, cgpa, degree);
    student.saveToCSV(fileName);

    std::cout << "\nStudent added successfully!\n";
}

void deleteStudent(const std::string& fileName, const std::string& studentID, std::vector<Student> studentList)
{
    std::vector<Student> newStudentList;
    if(findStudent(studentID, studentList))
    {
        for(auto it:studentList)
        {
            if(it.getSID() != studentID)
            {
                newStudentList.push_back(it);
            }
        }
        std::ofstream file(fileName);
        for(auto it:newStudentList)
        {
            it.saveToCSV(fileName);
        }
        file.close();
    }
    else
    {
        std::cout << "Student Not Found!\n";
    }
}

void alterStudent(const std::string& fileName, const std::string& studentID, std::vector<Student> studentList)
{
    Student* student = findStudent(studentID, studentList);
    if(student)
    {
        std::string name, address, department, degreeType;
        std::cout << "Enter Student's name (alter): ";
        std::getline(std::cin, name);
        std::cout << "Enter Student's Address (alter): ";
        std::getline(std::cin, address);
        std::cout << "Enter Student's department: ";
        std::cin >> department;
        std::cout << "Enter Student's Programme: ";
        std::cin >> degreeType;
        student->Setname(name);
        student->Setaddress(address);
        student->setDept(department);
        student->setDegreeType(degreeType);
        std::ofstream file(fileName);
        for(auto it:studentList)
        {
            it.saveToCSV(fileName);
        }
        file.close();
        std::cout << "Student Edited Successfully";
    }
    else
    {
        std::cout << "Student Not Found!";
    }
}

void getDetailedReport(std::string studentID, std::vector<courseStudent> courseStudentList, std::vector<Student> studentList)
{
    std::vector<courseStudent> report;
    Student* student = findStudent(studentID, studentList);

    if (student)
    {
        // Collect courses related to the student
        for ( auto& course : courseStudentList)
        {
            if (course.getSID() == studentID)
            {
                report.push_back(course);
            }
        }

        if (!report.empty())
        {
            std::cout << "\n========================================\n";
            std::cout << "          STUDENT REPORT                \n";
            std::cout << "========================================\n";
            std::cout << " Student Name  : " << student->Getname() << "\n";
            std::cout << " Student ID    : " << studentID << "\n";
            std::cout << "----------------------------------------\n";

            std::cout << " Past Courses  :\n";
            for ( auto& course : report)
            {
                if (course.getGrade() != "N/A")
                {
                    std::cout << "  - " << course.getcourseID() << " : " << course.getGrade() << "\n";
                }
            }

            std::cout << "\n Currently Taking :\n";
            for (auto& course : report)
            {
                if (course.getGrade() == "N/A")
                {
                    std::cout << "  - " << course.getcourseID() << "\n";
                }
            }
            std::cout << "========================================\n";
        }
        else
        {
            std::cout << " The student " << studentID << " hasn't enrolled in any course yet!\n";
        }
    }
    else
    {
        std::cout << " The student " << studentID << " doesn't exist.\n";
    }

    report.clear(); // Ensure memory is freed
}

void displayCurrentCourses(std::string studentID, std::vector<courseStudent> courseStudentList, std::vector<Student> studentList)
{
    std::vector<courseStudent> currentCourses;
    Student* student = findStudent(studentID, studentList);

    if (student)
    {
        // Collect current courses
        for ( auto& course : courseStudentList)
        {
            if (course.getSID() == studentID && course.getGrade() == "N/A")
            {
                currentCourses.push_back(course);
            }
        }

        std::cout << "\n========================================\n";
        std::cout << "          CURRENT COURSES               \n";
        std::cout << "========================================\n";

        if (!currentCourses.empty())
        {
            std::cout << " Student Name  : " << student->Getname() << "\n";
            std::cout << " Student ID    : " << studentID << "\n";
            std::cout << "----------------------------------------\n";
            for ( auto& course : currentCourses)
            {
                std::cout << "  - " << course.getcourseID() << "\n";
            }
        }
        else
        {
            std::cout << " No current enrollments found.\n";
        }

        std::cout << "========================================\n";
    }
    else
    {
        std::cout << " The student doesn't exist!\n";
    }
}

Faculty* findFaculty(const std::string& fid, std::vector<Faculty>& fc_vc)
{
    for(auto& faculty: fc_vc)
    {
        if(faculty.getFID()==fid)
        {
            return &faculty;
        }
    }
    return nullptr;
}

void displayFacultyDetails(std::string& FID, std::vector<Faculty> facultyList)
{
    Faculty* faculty = findFaculty(FID, facultyList);
    if(faculty)
    {
        faculty->displayFacultyInfo();
    }
    else
    {
        std::cout << "The faculty doesn't exist!\n";
    }
}

std::vector<Faculty> findFacultyByName(const std::string& name, std::vector<Faculty>& fc_vc)
{
    std::vector<Faculty> faculties;
    for(auto& faculty: fc_vc)
    {
        if(faculty.getFacultyName() == name)
        {
            faculties.push_back(faculty);
        }
    }
    return faculties;
}

std::vector<Faculty> filterFacultyByPost(std::vector<Faculty>& fc_vc, std::string post)
{
    std::vector<Faculty> faculties;
    for(auto it:fc_vc)
    {
        if(it.getPost() == post)
        {
            faculties.push_back(it);
        }
    }
    return faculties;
}

std::vector<std::string> getFacultyIdList(const std::string& fileName)
{
    std::vector<std::string> fid_list;
    std::ifstream inputFile(fileName);
    if(!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return fid_list;
    }
    std::string id;
    while(std::getline(inputFile, id))
    {
        fid_list.push_back(id);
    }
    inputFile.close();
    return fid_list;
}

void displayAllFaculty(std::vector<Faculty>& ft_vc)
{
    if (ft_vc.empty())
    {
        std::cout << "No faculty members available.\n";
        return;
    }

    std::cout << "\n========================================\n";
    std::cout << "           ALL FACULTY DETAILS\n";
    std::cout << "========================================\n";

    for ( auto& faculty : ft_vc)
    {
        faculty.displayFacultyInfo();
    }
}


void addFaculty(const std::string& fileName)
{
    std::string name, address, dept, fid, degree, post;
    float salary = 0.0;
    int age = -1;

    std::cout << "\n========================================\n";
    std::cout << "         ADD NEW FACULTY\n";
    std::cout << "========================================\n";

    std::cout << "Enter New Faculty Name      : ";
    std::getline(std::cin >> std::ws, name); // Ensures leading whitespace is ignored

    std::cout << "Enter New Faculty Address   : ";
    std::getline(std::cin, address);

    std::cout << "Enter New Faculty Department: ";
    std::getline(std::cin, dept);

    std::cout << "Enter New Faculty ID        : ";
    std::getline(std::cin, fid);

    std::cout << "Enter New Faculty Age       :";
    std::cin >> age;
    std::cin.ignore();

    std::cout << "Enter New Faculty Post      : ";
    std::getline(std::cin, post);

    std::cout << "Enter New Faculty Salary    : ";
    std::cin >> salary;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears input buffer

    std::cout << "========================================\n";

    Faculty faculty(fid, name, address, age, post, dept, salary);

    // Create a Faculty object with the entered details
    //Faculty faculty(name, address, dept, fid, degree, post, salary);
    faculty.saveToCSV(fileName);

    std::cout << "\nFaculty added successfully!\n";
}


void deleteFaculty(const std::string& fileName, const std::string& facultyID, std::vector<Faculty> facultyList)
{
    std::vector<Faculty> newFacultyList;
    if(findFaculty(facultyID, facultyList))
    {
        for(auto it:facultyList)
        {
            if(it.getFID() != facultyID)
            {
                newFacultyList.push_back(it);
            }
        }
        std::ofstream file(fileName);
        for(auto it:newFacultyList)
        {
            it.saveToCSV(fileName);
        }
        file.close();
    }
    else
    {
        std::cout << "Faculty Not Found\n";
    }
}

void alterFaculty(const std::string& fileName, const std::string& facultyID, std::vector<Faculty> facultyList)
{
    Faculty* faculty =  findFaculty(facultyID, facultyList);
    if(faculty)
    {
        std::string name, address, post;
        float salary;
        std::cout << "Enter Faculty Name (alter): ";
        std::getline(std::cin, name);
        std::cout << "Enter Faculty Address (alter):";
        std::getline(std::cin, address);
        std::cout << "Enter Faculty Post (alter): ";
        std::getline(std::cin, post);
        std::cout << "Enter Faculty Salary (alter): ";
        std::cin >> salary;
        std::cin.ignore();

        faculty->Setname(name);
        faculty->Setaddress(address);
        faculty->setPost(post);
        faculty->setSalary(salary);

        std::ofstream file(fileName);
        for(auto it:facultyList)
        {
            it.saveToCSV(fileName);
        }
        file.close();
        std::cout << "Faculty Info Edited Successfully";
    }
    else
    {
        std::cout << "Faculty Not Found\n";
    }
}

void coursesTakenByFaculty(std::string& FID, std::vector<Course> courseList)
{
    std::vector<Course> coursesBy;
    for(auto it:courseList)
    {
        if(it.getFID() == FID)
        {
            coursesBy.push_back(it);
        }
    }
    if(!coursesBy.empty())
    {
        for(auto it:coursesBy)
        {
            std::cout << it.getcourseID() << std::endl;
        }
    }
    else
    {
        std::cout << "You are not taking any courses this semster!\n";
    }
}

void calculateGPA(std::string studentID, std::vector<courseStudent> courseStudentList)
{
    std::map<std::string, float> gradePoints =
    {
        {"A+", 4.0}, {"A", 3.75}, {"A-", 3.5},
        {"B+", 3.25}, {"B", 3.0}, {"B-", 2.75},
        {"C+", 2.5}, {"C", 2.25}, {"D", 2.0}, {"F", 0.0}
    };
    float cgpa = 0;
    std::vector<std::string> gradeList;
    for(int i=0; i<courseStudentList.size(); i++)
    {
        if(courseStudentList[i].getSID() == studentID)
        {
            gradeList.push_back(courseStudentList[i].getGrade());
        }
    }
    for(int i=0; i<gradeList.size(); i++)
    {
        cgpa+=gradePoints[gradeList[i]];
    }
    cgpa /= gradeList.size();
    std::cout << "Result of " << studentID << ": " << std::fixed << std::setprecision(2) << cgpa << std::endl;
}


void addCourse(std::string courseID, std::string courseTitle, std::string FID, float credit, const std::string& fileName)
{
    Course course(courseID, courseTitle, FID, credit);
    course.saveToCSV(fileName);
}

Course* findCourse(std::string courseID, std::vector<Course> courseList)
{
    for(auto& course:courseList)
    {
        if(course.getcourseID() == courseID)
        {
            return &course;
        }
    }
    return nullptr;
}

void enrollStudent(std::string studentID, std::string courseID, std::vector<Course> courseList, std::vector<Student> studentList, const std::string& fileName)
{
    Course* course = findCourse(courseID, courseList);
    Student* student = findStudent(studentID, studentList);
    if(course && student)
    {
        courseStudent cstudent(courseID, studentID, "N/A");
        cstudent.saveToCSV(fileName);
    }
    else
    {
        std::cout << "Cannot Enroll. Student or Course doesn't Exist.\n";
    }

}

void displayInventory()
{
    Library library({}, {}, {});
    library.loadData();
    std::cout << "Available Inventory: \n";
    for(auto it:library.getInventory())
    {
        it.displayBook();
    }
}

void displayBorrowedBooks()
{
    Library library({}, {}, {});
    library.loadData();
    std::cout << "Books that have been borrowed: \n";
    for(auto it:library.getBorrowedBooks())
    {
        it.displayBook();
    }
}

void displayArchivedBooks()
{
    Library library({}, {}, {});
    library.loadData();
    for(auto it:library.getArchivedBooks())
    {
        it.displayBook();
    }
}

void personBorrowBook(std::string& id)
{
    struct
    {
        std::string isbn;
        std::string pid;
    } personBook;

    displayInventory();

    std::string isbn;
    std::cout << "Desired Book: ";
    std::cin >> isbn;

    Library library({}, {}, {});
    library.loadData();
    library.borrowBook(isbn);

    // Assigning values to struct
    personBook.isbn = isbn;
    personBook.pid = id;

    // Open file in append mode
    std::ofstream file("Borrowed_Books.csv", std::ios::app);

    // Check if the file is open
    if (!file)
    {
        std::cerr << "Error: Could not open Borrowed_Books.csv for writing!\n";
        return;
    }

    // Write data in CSV format
    file << personBook.isbn << "," << personBook.pid << "\n";

    // Close file
    file.close();
}


void personReturnBook()
{
    displayBorrowedBooks();
    std::string isbn;
    std::cout << "ISBN of the Book: \n";
    std::cin >> isbn;
    Library library({}, {}, {});
    library.loadData();
    library.returnBook(isbn);
}

void viewBorrowedBooks(std::string& id)
{
    std::ifstream file("Borrowed_Books.csv");

    // Check if the file opened successfully
    if (!file)
    {
        std::cerr << "Error: Could not open Borrowed_Books.csv for reading!\n";
        return;
    }

    std::vector<std::pair<std::string, std::string>> books;
    std::string line;

    // Read each line from the file
    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');

        // Ensure the line is properly formatted
        if (commaPos == std::string::npos) continue;

        std::string isbn = line.substr(0, commaPos);
        std::string pid = line.substr(commaPos + 1);

        // Store and display only if the id matches
        if (pid == id)
        {
            books.emplace_back(isbn, pid);
        }
    }

    file.close();

    // Display the borrowed books for the given ID
    if (books.empty())
    {
        std::cout << "No borrowed books found for ID: " << id << "\n";
    }
    else
    {
        std::cout << "Borrowed books for ID " << id << ":\n";
        for (const auto& book : books)
        {
            std::cout << "ISBN: " << book.first << "\n";
        }
    }
}


void cafeteria()
{
    std::vector<Dish> menu =
    {
        Dish("Pasta", {"Noodles", "Tomato Sauce", "Cheese"}, 2.5, "Lunch", 8.99),
        Dish("Burger", {"Bun", "Beef Patty", "Lettuce", "Tomato", "Cheese"}, 3.0, "Dinner", 6.99),
        Dish("Salad", {"Lettuce", "Tomato", "Cucumber", "Olive Oil"}, 1.0, "Snack", 4.99),
        Dish("Omelette", {"Eggs", "Salt", "Pepper", "Cheese"}, 1.5, "Breakfast", 5.49)
    };

    std::cout << "Available Dishes:\n";
    for (size_t i = 0; i < menu.size(); i++)
    {
        std::cout << i + 1 << ". ";
        menu[i].displayDish();
    }

    std::cout << "\n========================================\n";
    std::cout << "          PLACE YOUR ORDER              \n";
    std::cout << "========================================\n";
    std::cout << " Enter the number of the dish you want to order: ";

    int choice;
    std::cin >> choice;

// Validate dish selection
    if (choice < 1 || choice > menu.size())
    {
        std::cout << " Invalid selection. Please try again.\n";
        return;
    }

    Dish selectedDish = menu[choice - 1];
    std::cout << "\n========================================\n";
    std::cout << " You ordered: " << selectedDish.getName() << "\n";
    std::cout << "========================================\n";

// Payment method selection
    std::cout << " Select a payment method:\n";
    std::cout << " 1. Cash\n";
    std::cout << " 2. Card\n";
    std::cout << " 3. Digital\n";
    std::cout << " Enter your choice: ";

    int paymentChoice;
    std::cin >> paymentChoice;

// Process payment
    PaymentMethod method = static_cast<PaymentMethod>(paymentChoice - 1);
    Payment payment(selectedDish.getPrice(), method);
    payment.processPayment();

    std::cout << "\n========================================\n";
    std::cout << " Your order has been placed successfully!\n";
    std::cout << " The food will be delivered soon. Enjoy!\n";
    std::cout << "========================================\n";

}

void findBook(std::string& isbn)
{
    Library library({}, {}, {});
    library.loadData();

    std::vector<Book> availableBooks = library.getInventory();

    for(auto it:availableBooks)
    {
        if(it.getISBN() == isbn)
        {
            it.displayBook();
            availableBooks.clear();
            return;
        }
    }
    std::cout << "Book Not Found!\n";
    availableBooks.clear();
}


