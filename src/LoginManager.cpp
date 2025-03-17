#include "LoginManager.h"



studentLogin::studentLogin(std::string id, std::vector<Student> studentList)
{
    this->id = id;
    this->studentList = studentList;
}

studentLogin::~studentLogin() {}

/*
void studentLogin::loginView(){
    Student st("", "", 1, "", "", 3, 1.00, "");
    std::vector<Student> stList = st.loadFromCSV("student.csv");
    courseStudent cstudent("", "", "");
    std::vector<courseStudent> csvct1 = {
        {"CSE 4301", "220041103", "A+"},
        {"CSE 4302", "220041103", "A+"},
        {"CSE 4303", "220041103", "B+"},
        {"CSE 4304", "220041103", "A+"},
        {"CSE 4305", "220041103", "N/A"},
        {"CSE 4306", "220041103", "N/A"},
        {"CSE 4307", "220041103", "N/A"}
    };
    int choice = -1;
    bool isTrue = true;
    while(isTrue){
        std::cout << "1. My Details\n";
        std::cout << "2. My Report\n";
        std::cout << "3. Current Courses\n";
        std::cout << "4. Cafeteria\n";
        std::cout << "5. Borrow A Book\n";
        std::cout << "6. Return A Book\n";
        std::cout << "7. Quit\n";

        std::cout << "Enter your Choice: ";
        std::cin >> choice;

        switch(choice){
        case 1:
            displayStudentDetails(id, stList);
            break;
        case 2:
            getDetailedReport(id, csvct1, studentList);
            break;
        case 3:
            displayCurrentCourses(id, csvct1, studentList);
            break;
        case 4:
            cafeteria();
            break;
        case 5:
            personBorrowBook();
            break;
        case 6:
            personReturnBook();
            break;
        case 7:
            isTrue = false;
            break;
        default:
            break;
        }
    }
}
*/
void studentLogin::loginView()
{
    Student st("", "", 1, "", "", 3, 1.00, "");
    std::vector<Student> stList = st.loadFromCSV("student.csv");
    courseStudent cstudent("", "", "");
    std::vector<courseStudent> csvct1 =
    {
        {"CSE 4301", "220041103", "A+"},
        {"CSE 4302", "220041103", "A+"},
        {"CSE 4303", "220041103", "B+"},
        {"CSE 4304", "220041103", "A+"},
        {"CSE 4305", "220041103", "N/A"},
        {"CSE 4306", "220041103", "N/A"},
        {"CSE 4307", "220041103", "N/A"}
    };
    int choice = -1;
    bool isTrue = true;
    while (isTrue)
    {
        std::cout << "\n========================================\n";
        std::cout << "            STUDENT PORTAL            \n";
        std::cout << "========================================\n";
        std::cout << " 1. My Details                         \n";
        std::cout << " 2. My Report                          \n";
        std::cout << " 3. Current Courses                    \n";
        std::cout << " 4. Cafeteria                          \n";
        std::cout << " 5. Library                            \n";
        std::cout << " 6. Quit                               \n";
        std::cout << "========================================\n";
        std::cout << " Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            displayStudentDetails(id, stList);
            break;
        case 2:
            getDetailedReport(id, csvct1, studentList);
            break;
        case 3:
            displayCurrentCourses(id, csvct1, studentList);
            break;
        case 4:
            cafeteria();
            break;
        case 5:
            int libraryChoice;
            std::cout << "\n========================================\n";
            std::cout << "               LIBRARY MENU             \n";
            std::cout << "========================================\n";
            std::cout << " 1. Borrow a Book                       \n";
            std::cout << " 2. Return a Book                       \n";
            std::cout << " 3. Search for a Book                   \n";
            std::cout << " 4. View Borrowed Books                 \n";
            std::cout << " 5. Back to Main Menu                   \n";
            std::cout << "========================================\n";
            std::cout << " Enter your choice: ";
            std::cin >> libraryChoice;

            switch (libraryChoice)
            {
            case 1:
                personBorrowBook(id);
                break;
            case 2:
                personReturnBook();
                break;
            case 3:
            {
                std::string isbn;
                std::cout << "Enter ISBN: ";
                std::cin >> isbn;
                findBook(isbn);
                break;
            }
            case 4:
                viewBorrowedBooks(id);
                break;
            case 5:
                break;
            default:
                std::cout << " Invalid choice! Please try again.\n";
                break;
            }
            break;
        case 6:
            std::cout << "\nExiting Student Portal...\n";
            isTrue = false;
            break;
        default:
            std::cout << " Invalid choice! Please enter a valid option.\n";
            break;
        }
    }
}
facultyLogin::facultyLogin(std::string id)
{
    this->id = id;
}

facultyLogin::~facultyLogin() {}

void facultyLogin::loginView()
{
    Faculty f("", "", "", 1, "", "", 0);
    std::vector<Faculty> facultyList = f.loadFromCSV("faculty.csv");

    Course c("", "", "", 0);
    std::vector<Course> courseList = c.loadFromCSV("course.csv");

    int choice = -1;
    bool isTrue = true;

    while(isTrue)
    {
        std::cout << "1. See Details\n";
        std::cout << "2. See My Courses\n";
        std::cout << "3. See My Student List\n";
        std::cout << "4. Borrow A Book\n";
        std::cout << "5. Return A Book\n";
        std::cout << "6. Go to Cafeteria\n";
        std::cout << "7. Quit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice)
        {
        case 1:
            displayFacultyDetails(id, facultyList);
            break;
        case 2:
            coursesTakenByFaculty(id, courseList);
            break;
        case 3:
            std::cout << "Option 3\n";
            break;
        case 4:
            personBorrowBook(id);
            break;
        case 5:
            personReturnBook();
            break;
        case 6:
            cafeteria();
            break;
        case 7:
            isTrue = false;
            break;
        }
    }
}


adminLogin::adminLogin(std::string id)
{
    this->id = id;
}

void adminLogin::loginView()
{
    Student s("", "", 1, "", "", 3, 1.0, "");
    std::vector<Student> studentList = s.loadFromCSV("student.csv");
    Faculty f("", "", "", 1, "", "", 0);
    std::vector<Faculty> facultyList = f.loadFromCSV("faculty.csv");
    while (true)
    {
        std::cout << "\n=============================\n";
        std::cout << "        ADMIN LOGIN\n";
        std::cout << "=============================\n";
        std::cout << "1. Student Functions\n";
        std::cout << "2. Faculty Functions\n";
        std::cout << "3. Library Functions\n";
        std::cout << "4. Exit\n";
        std::cout << "=============================\n";

        int choice = -1;
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            while (true)
            {
                std::cout << "\n=============================\n";
                std::cout << "      STUDENT FUNCTIONS\n";
                std::cout << "=============================\n";
                std::cout << "1. Display All Students\n";
                std::cout << "2. Add A Student\n";
                std::cout << "3. Alter A Student\n";
                std::cout << "4. Delete A Student\n";
                std::cout << "5. Get Student Info\n";
                std::cout << "6. Back to Main Menu\n";
                std::cout << "=============================\n";

                int sChoice = -1;
                std::cout << "Enter Your Choice: ";
                std::cin >> sChoice;

                if (sChoice == 6) break; // Return to main menu

                switch (sChoice)
                {
                case 1:
                    displayAllStudents(studentList);
                    break;
                case 2:
                {
                    addStudent("student.csv");
                    studentList = s.loadFromCSV("student.csv");
                    break;
                }

                case 3:
                {
                    std::cout << "Enter SID: ";
                    std::string sid;
                    std::cin >> sid;
                    alterStudent("student.csv", sid, studentList);
                    studentList = s.loadFromCSV("student.csv");
                    break;
                }

                case 4:
                {
                    std::cout << "Enter SID: ";
                    std::string sid;
                    std::cin >> sid;
                    deleteStudent("student.csv", sid, studentList);
                    studentList = s.loadFromCSV("student.csv");
                    break;
                }

                case 5:
                {
                    std::cout << "Enter SID: ";
                    std::string sid;
                    std::cin >> sid;
                    displayStudentDetails(sid, studentList);
                }
                default:
                    std::cout << "Invalid choice! Try again.\n";
                }
            }
            break;
        }

        case 2:   // Faculty Functions
        {
            while (true)   // Faculty menu loop
            {
                std::cout << "\n=============================\n";
                std::cout << "      FACULTY FUNCTIONS\n";
                std::cout << "=============================\n";
                std::cout << "1. Display All Faculties\n";
                std::cout << "2. Add A Faculty\n";
                std::cout << "3. Alter A Faculty\n";
                std::cout << "4. Delete A Faculty\n";
                std::cout << "5. Get Faculty Info\n";
                std::cout << "6. Back to Main Menu\n";
                std::cout << "=============================\n";

                int fChoice = -1;
                std::cout << "Enter Your Choice: ";
                std::cin >> fChoice;
                std::cin.ignore();

                if (fChoice == 6) break; // Return to main menu

                switch (fChoice)
                {
                case 1:
                    displayAllFaculty(facultyList);
                    break;
                case 2:
                    addFaculty("faculty.csv");
                    facultyList = f.loadFromCSV("faculty.csv");
                    break;
                case 3:
                {
                    std::cout << "Enter FID: ";
                    //std::cin.ignore();
                    std::string fid;
                    std::cin >> fid;
                    std::cin.ignore();
                    alterFaculty("faculty.csv", fid, facultyList);
                    facultyList = f.loadFromCSV("faculty.csv");
                    break;
                }
                case 4:
                {
                    std::cout << "Enter FID: ";
                    std::string fid;
                    std::cin >> fid;
                    deleteFaculty("faculty.csv", fid, facultyList);
                    facultyList = f.loadFromCSV("faculty.csv");
                    break;
                }
                case 5:
                {
                    std::cout << "Enter FID: ";
                    std::string fid;
                    std::cin >> fid;
                    displayFacultyDetails(fid, facultyList);
                    break;
                }

                default:
                    std::cout << "Invalid choice! Try again.\n";
                    break;
                }
            }
        }

        case 3:   // Library Functions
        {
            while (true)   // Library menu loop
            {
                std::cout << "\n=============================\n";
                std::cout << "      LIBRARY FUNCTIONS\n";
                std::cout << "=============================\n";
                std::cout << "1. View Library Inventory\n";
                std::cout << "2. View Borrowed Books\n";
                std::cout << "3. View Archived Books\n";
                std::cout << "4. Add A Book\n";
                std::cout << "5. Remove A Book\n";
                //std::cout << "6. Archive A Book\n";
                std::cout << "6. Back to Main Menu\n";
                std::cout << "=============================\n";

                int lChoice = -1;
                std::cout << "Enter Your Choice: ";
                std::cin >> lChoice;

                if (lChoice == 6) break; // Return to main menu

                switch (lChoice)
                {
                case 1:
                    displayInventory();
                    break;
                case 2:
                    displayBorrowedBooks();
                    break;
                case 3: /* View archived books function */
                    displayArchivedBooks();
                    break;
                case 4: /* Add a book function */
                {
                    Library library({}, {}, {});
                    std::string title, author, isbn;
                    int count = 0;
                    std::cin.ignore();

                    std::cout << "Enter Title    : ";
                    std::getline(std::cin, title); // Get the book title

                    std::cout << "Enter Author   : ";
                    std::getline(std::cin, author); // Get the book author

                    std::cout << "Enter ISBN     : ";
                    std::getline(std::cin, isbn); // Get the ISBN (as string to handle special characters)

                    std::cout << "Enter Count    : ";
                    std::cin >> count; // Get the count of books

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    Book book(title, author, isbn, count);
                    library.addBook(book);
                    break;
                }

                case 5: /* Remove a book function */
                {
                    Library library({}, {}, {});
                    library.archiveBook();
                    break;
                }
                default:
                    std::cout << "Invalid choice! Try again.\n";
                    break;
                }
            }
            break;
        }

        case 4:
            std::cout << "Exiting...\n";
            return; // Quit program

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    }
}

adminLogin::~adminLogin() {}

//guestLogin::~guestLogin() {}
