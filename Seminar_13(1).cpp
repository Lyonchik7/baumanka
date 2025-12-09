#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title; 
    string author; 
    int year; 

    void displayInfo() {
        cout << "Название: " << title << ", Автор: " << author << ", Год: " << year << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Book myBook;

    myBook.title = "Война и мир";
    myBook.author = "Лев Толстой";
    myBook.year = 1869;

    myBook.displayInfo();

    return 0;
}