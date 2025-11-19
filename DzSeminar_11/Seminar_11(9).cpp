#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

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

    // Чтение файла
    ifstream file("products_manual.csv");
    vector<Product> products;
    string line;

    getline(file, line); // заголовок

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, category, priceStr, quantityStr;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, priceStr, ',');
        getline(ss, quantityStr, ',');

        products.push_back({ stoi(id), name, category, stod(priceStr), stoi(quantityStr) });
    }
    file.close();

    cout << "Загружено товаров: " << products.size() << endl;

    // Лямбда-функции для сортировки
    auto priceAsc = [](const Product& a, const Product& b) { return a.price < b.price; };
    auto priceDesc = [](const Product& a, const Product& b) { return a.price > b.price; };
    auto nameAsc = [](const Product& a, const Product& b) { return a.name < b.name; };
    auto quantityDesc = [](const Product& a, const Product& b) { return a.quantity > b.quantity; };

    // Сортировка по цене (возрастание)
    vector<Product> sortedByPrice = products;
    sort(sortedByPrice.begin(), sortedByPrice.end(), priceAsc);

    cout << "\nСортировка по цене (от дешевых к дорогим):" << endl;
    for (const auto& p : sortedByPrice) {
        cout << p.name << " - " << p.price << " руб." << endl;
    }

    // Сохранение в файл
    ofstream out("sorted_products.csv");
    out << "id,name,category,price,quantity" << endl;
    for (const auto& p : sortedByPrice) {
        out << p.id << "," << p.name << "," << p.category << ","
            << fixed << setprecision(2) << p.price << "," << p.quantity << endl;
    }
    out.close();

    cout << "Сохранено в sorted_products.csv" << endl;

    return 0;
}