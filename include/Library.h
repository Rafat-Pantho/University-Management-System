#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

class Book
{
    private:
        std::string title;
        std::string author;
        std::string isbn;
        int count;
    public:
        Book(std::string title, std::string author, std::string isbn, int count=1);
        ~Book();

        std::string getTitle() const { return title; }
        std::string getAuthor() const { return author; }
        std::string getISBN() const { return isbn; }
        int getCount() const { return count; }

        void setCount(int c) { count = c; }
        void incrementCount(int amount = 1) { count += amount; }
        void decrementCount(int amount = 1) { count -= amount; }

        void displayBook()const;
};


class Library{
private:
    std::vector<Book> inventory;
    std::vector<Book> borrowedBooks;
    std::vector<Book> archivedBooks;

    auto findBook(std::vector<Book>& collection, const std::string& isbn) {
        return find_if(collection.begin(), collection.end(),
            [&isbn](const Book& b) { return b.getISBN() == isbn; });
    }
public:
    Library(std::vector<Book> inventory, std::vector<Book> borrowedBooks, std::vector<Book> archivedBooks);
    ~Library();

    std::vector<Book> getInventory(){return inventory;}
    std::vector<Book> getBorrowedBooks(){return borrowedBooks;}
    std::vector<Book> getArchivedBooks(){return archivedBooks;}

    void addBook(Book& book);
    void archiveBook();
    void borrowBook(const std::string &isbn);
    void returnBook(const std::string &isbn);
    void saveData()const;
    void loadData();
};


#endif // LIBRARY_H
