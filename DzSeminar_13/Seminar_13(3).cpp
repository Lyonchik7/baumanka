#include <iostream>
#include <string>
using namespace std;


class Book {
private:
    string title;    // Название книги
    string author;   // Автор книги
    int year;        // Год выпуска

public:
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    void displayInfo() {
        cout << "Название: " << title << ", Автор: " << author << ", Год выпуска: " << year << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Book myBook("Война и мир", "Лев Толстой", 1869);

    cout << "Информация о книге:" << endl;
    myBook.displayInfo();

    return 0;
}