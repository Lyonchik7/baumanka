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

    // Лямбда-фильтры
    auto expensive = [](const Product& p) { return p.price > 5000; };
    auto electronics = [](const Product& p) { return p.category == "Электроника"; };
    auto inStock = [](const Product& p) { return p.quantity > 10; };

    // Фильтрация
    vector<Product> filtered;

    // Товары дороже 5000 рублей
    copy_if(products.begin(), products.end(), back_inserter(filtered), expensive);

    cout << "\nТовары дороже 5000 руб.: " << filtered.size() << endl;
    for (const auto& p : filtered) {
        cout << p.name << " - " << p.price << " руб." << endl;
    }

    // Сохранение в файл
    ofstream out("filtered_products.csv");
    out << "id,name,category,price,quantity" << endl;
    for (const auto& p : filtered) {
        out << p.id << "," << p.name << "," << p.category << ","
            << fixed << setprecision(2) << p.price << "," << p.quantity << endl;
    }
    out.close();

    cout << "Сохранено в filtered_products.csv" << endl;

    return 0;
}