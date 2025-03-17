#include "Library.h"

#include <iomanip>
Book::Book(std::string title, std::string author, std::string isbn, int count)
{
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->count = count;
}

Book::~Book() {};

void Book::displayBook() const
{
    std::cout << "\n----------------------------------------\n";
    std::cout << "               Book Details             \n";
    std::cout << "----------------------------------------\n";
    std::cout << std::left << std::setw(10) << "Title: "  << title  << std::endl;
    std::cout << std::left << std::setw(10) << "Author: " << author << std::endl;
    std::cout << std::left << std::setw(10) << "ISBN: "   << isbn   << std::endl;
    std::cout << std::left << std::setw(10) << "Copies: " << count  << std::endl;
    std::cout << "----------------------------------------\n";
}

Library::Library(std::vector<Book> inventory, std::vector<Book> borrowedBooks, std::vector<Book> archivedBooks)
{
    this->inventory = inventory;
    this->borrowedBooks = borrowedBooks;
    this->archivedBooks = archivedBooks;
}

Library::~Library() {}

void Library::addBook(Book& book)
{

    auto it = findBook(inventory, book.getISBN());
    if (it != inventory.end())
    {
        it->incrementCount(book.getCount());
    }
    else
    {
        inventory.push_back(book);
    }

    saveData();
}


void Library::archiveBook()
{
    std::string isbn;
    std::cout << "Enter ISBN of the book to archive: ";
    std::cin >> isbn;

    // Find the book in the inventory
    auto it = findBook(inventory, isbn);
    if (it != inventory.end())
    {
        // Add the book to archivedBooks and remove it from inventory
        archivedBooks.push_back(*it);
        inventory.erase(it);

        std::cout << "Book with ISBN " << isbn << " has been archived successfully." << std::endl;
    }
    else
    {
        std::cout << "Book with ISBN " << isbn << " not found in inventory." << std::endl;
    }

    // Save updated data
    saveData();
}


void Library::borrowBook(const std::string& isbn)
{
    auto it = findBook(inventory, isbn);
    if (it != inventory.end() && it->getCount() > 0)
    {
        borrowedBooks.emplace_back(it->getTitle(), it->getAuthor(), it->getISBN(), 1);
        it->decrementCount();
        if (it->getCount() == 0)
        {
            inventory.erase(it);
        }
        std::cout << "Book borrowed successfully." << std::endl;
    }
    else
    {
        std::cout << "Book not available for borrowing." << std::endl;
    }
    saveData();
}

void Library::returnBook(const std::string& isbn)
{
    auto borrowIt = findBook(borrowedBooks, isbn);
    if (borrowIt != borrowedBooks.end())
    {
        // Add back to inventory
        auto invIt = findBook(inventory, isbn);
        if (invIt != inventory.end())
        {
            invIt->incrementCount();
        }
        else
        {
            inventory.emplace_back(borrowIt->getTitle(),
                                   borrowIt->getAuthor(),
                                   borrowIt->getISBN(), 1);
        }
        borrowedBooks.erase(borrowIt);
        std::cout << "Book returned successfully." << std::endl;
    }
    else
    {
        std::cout << "Book not found in borrowed list." << std::endl;
    }
    saveData();
}

void Library::saveData() const
{
    std::ofstream invFile("inventory.csv"), borFile("borrowed.csv"), arcFile("archived.csv");

    for (const auto& book : inventory)
        invFile << book.getTitle() << "," << book.getAuthor() << ","
                << book.getISBN() << "," << book.getCount() << "\n";

    for (const auto& book : borrowedBooks)
        borFile << book.getTitle() << "," << book.getAuthor() << ","
                << book.getISBN() << "," << book.getCount() << "\n";

    for (const auto& book : archivedBooks)
        arcFile << book.getTitle() << "," << book.getAuthor() << ","
                << book.getISBN() << "," << book.getCount() << "\n";
}

void Library::loadData()
{
    inventory.clear();
    borrowedBooks.clear();
    archivedBooks.clear();

    std::ifstream invFile("inventory.csv"), borFile("borrowed.csv"), arcFile("archived.csv");
    std::string line, title, author, isbn, countStr;

    auto loadCollection = [](std::ifstream& file, std::vector<Book>& collection)
    {
        std::string line, title, author, isbn, countStr;

        while (getline(file, line))
        {
            std::stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, isbn, ',');
            getline(ss, countStr);

            try
            {
                int count = std::stoi(countStr);
                collection.emplace_back(title, author, isbn, count);
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error parsing count for book: " << title << " (" << e.what() << ")" << std::endl;
            }
        }
    };


    loadCollection(invFile, inventory);
    loadCollection(borFile, borrowedBooks);
    loadCollection(arcFile, archivedBooks);
}


