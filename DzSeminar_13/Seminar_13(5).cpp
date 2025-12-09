#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Publication {
protected:
    string title;

public:
    Publication(string t) : title(t) {}
};

class Book : public Publication {
private:
    string author;
    int year;

public:
    Book(string t, string a, int y) : Publication(t), author(a), year(y) {}

    void displayInfo() {
        cout << "Название: " << title << ", Автор: " << author << ", Год выпуска: " << year << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string title, author;
    int year;

    cout << "Введите информацию о книге:" << endl;

    cout << "Название книги: ";
    getline(cin, title);

    cout << "Автор книги: ";
    getline(cin, author);

    cout << "Год выпуска: ";
    cin >> year;

    
    Book userBook(title, author, year);

    cout << "\nИнформация о книге:" << endl;
    userBook.displayInfo();

    return 0;
}