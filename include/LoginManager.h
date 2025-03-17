#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include "../Helpers.h"

#include <iostream>

class LoginViewer{
public:
    virtual void loginView()=0;
};


class studentLogin:public LoginViewer{
private:
    std::string id;
    std::vector<Student> studentList;
public:
    studentLogin(std::string id, std::vector<Student> studentList);
    ~studentLogin();

    std::string getID(){return id;}

    void loginView() override;
};

class facultyLogin:public LoginViewer{
private:
    std::string id;
public:
    facultyLogin(std::string id);
    ~facultyLogin();

    std::string getID(){return id;}

    void loginView() override;
};

class adminLogin:public LoginViewer{
private:
    std::string id = "Admin";
public:
     adminLogin(std::string id);
    ~adminLogin();

    std::string getID(){return id;}
    void loginView();
};

class guestLogin:public LoginViewer{
private:
    std::string id = "Guest";
public:
    ~guestLogin();

    std::string getID(){return id;}
};

#endif // LOGINMANAGER_H
