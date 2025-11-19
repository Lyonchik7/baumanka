#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

int main()
{
    setlocale(LC_ALL, "RU");

    // Минимальные тестовые данные
    vector<Product> products = {
        {1, "Ноутбук Dell", "Электроника", 45000.00, 5},
        {2, "Мышь Bluetooth", "Аксессуары", 2500.50, 15},
        {3, "Клавиатура", "Аксессуары", 3500.75, 8},
        {4, "Наушники", "Аудиотехника", 5600.00, 12},
        {5, "Флешка 64GB", "Электроника", 1200.00, 25}
    };

    // Запись в CSV
    ofstream file("products_manual.csv");
    file << "id,name,category,price,quantity" << endl;

    for (const auto& p : products) {
        file << p.id << "," << p.name << "," << p.category << ","
            << fixed << p.price << "," << p.quantity << endl;
    }

    file.close();

    cout << "Создан CSV файл с " << products.size() << " товарами" << endl;
    return 0;
}