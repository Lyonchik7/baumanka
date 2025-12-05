#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

struct Library {
    Book books[100];
    int count = 0; 
};

void showMenu() {
    cout << "\n Библиотека \n";
    cout << "1. Добавить книгу\n";
    cout << "2. Удалить книгу\n";
    cout << "3. Найти по автору\n";
    cout << "4. Показать все\n";
    cout << "5. Выход\n";
    cout << "Выберите: ";
}

void addBook(Library& lib) {
    if (lib.count >= 100) {
        cout << "Библиотека полна!\n";
        return;
    }

    cout << "\nНазвание: ";
    cin.ignore();
    getline(cin, lib.books[lib.count].title);

    cout << "Автор: ";
    getline(cin, lib.books[lib.count].author);

    cout << "Год: ";
    cin >> lib.books[lib.count].year;

    cout << "Жанр: ";
    cin.ignore();
    getline(cin, lib.books[lib.count].genre);

    lib.count++;
    cout << "Книга добавлена!\n";
}

void deleteBook(Library& lib) {
    if (lib.count == 0) {
        cout << "Библиотека пуста!\n";
        return;
    }

    string title;
    cout << "Название для удаления: ";
    cin.ignore();
    getline(cin, title);

    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].title == title) {
            // Сдвигаем книги
            for (int j = i; j < lib.count - 1; j++) {
                lib.books[j] = lib.books[j + 1];
            }
            lib.count--;
            cout << "Книга удалена!\n";
            return;
        }
    }

    cout << "Книга не найдена!\n";
}

void findBooks(const Library& lib) {
    if (lib.count == 0) {
        cout << "Библиотека пуста!\n";
        return;
    }

    string author;
    cout << "Автор для поиска: ";
    cin.ignore();
    getline(cin, author);

    bool found = false;
    cout << "\nКниги автора " << author << ":\n";

    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].author == author) {
            cout << "- " << lib.books[i].title;
            cout << " (" << lib.books[i].year << ")\n";
            cout << "  Жанр: " << lib.books[i].genre << "\n\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Книги не найдены\n";
    }
}

void showAll(const Library& lib) {
    if (lib.count == 0) {
        cout << "Библиотека пуста!\n";
        return;
    }

    cout << "\nВсего книг: " << lib.count << "\n\n";

    for (int i = 0; i < lib.count; i++) {
        cout << i + 1 << ". " << lib.books[i].title << "\n";
        cout << "   Автор: " << lib.books[i].author << "\n";
        cout << "   Год: " << lib.books[i].year << "\n";
        cout << "   Жанр: " << lib.books[i].genre << "\n\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Library lib;

    lib.books[0] = { "Война и мир", "Лев Толстой", 1869, "Роман" };
    lib.books[1] = { "Преступление и наказание", "Федор Достоевский", 1866, "Роман" };
    lib.books[2] = { "Мастер и Маргарита", "Михаил Булгаков", 1967, "Роман" };
    lib.count = 3;

    cout << "Управление библиотекой\n";
    cout << "В библиотеке: " << lib.count << " книги\n";

    int choice = 0;

    while (choice != 5) {
        showMenu();
        cin >> choice;

        if (choice == 1) addBook(lib);
        else if (choice == 2) deleteBook(lib);
        else if (choice == 3) findBooks(lib);
        else if (choice == 4) showAll(lib);
        else if (choice == 5) cout << "Выход\n";
        else {
            cout << "Ошибка! Выберите 1-5\n";
            cin.clear();
            while (cin.get() != '\n'); // простая очистка буфера
        }
    }

    return 0;
}