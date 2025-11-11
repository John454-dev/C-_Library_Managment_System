#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    int year;

    void input()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Year of Publication: ";
        cin >> year;
    }
    void display() const
    {
        cout << "\nBook ID: " << id
             << "\nTitle: " << title << "\nAuthor: " << author << "\nYear: " << year;
    }
};

class Library
{
private:
    vector<Book> books;

public:
    void addbook()
    {
        Book b;
        b.input();
        books.push_back(b);
        cout << "\nBook added successfully!\n";
    }

    void showbooks() const
    {
        if (books.empty())
        {
            cout << "\nNo book available.\n";
            return;
        }

        cout << "****** List of Books ******";
        for (const auto &b : books)
        {
            b.display();
        }
    }
};

int main()
{
    Library lb;
    int choice;

    do
    {
        cout << "\n**** Library Managment System ****\n";
        cout << "1. Add Book\n";
        cout << "2. Show all Books\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lb.addbook();
            break;
        case 2:
            lb.showbooks();
            break;
        case 3:
            cout << "\nExiting program...\n";
            break;
        default:
            cout << "\nInvalid choice...\n";
        }
    } while (choice != 3);

    return 0;
}