#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    ifstream file("products.csv");
    if (!file.is_open()) {
        cout << "Файл не найден!" << endl;
        return 1;
    }

    string line;
    getline(file, line); // Заголовок

    double totalValue = 0;
    int totalQuantity = 0;
    double maxPrice = 0, minPrice = 1e9;
    string maxProduct, minProduct;

    cout << "Список товаров:" << endl;
    cout << "----------------" << endl;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, category, priceStr, quantityStr;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, priceStr, ',');
        getline(ss, quantityStr, ',');

        double price = stod(priceStr);
        int quantity = stoi(quantityStr);

        // Вывод товара
        cout << name << " - " << price << " руб. (" << quantity << " шт.)" << endl;

        // Статистика
        totalValue += price * quantity;
        totalQuantity += quantity;

        if (price > maxPrice) {
            maxPrice = price;
            maxProduct = name;
        }
        if (price < minPrice) {
            minPrice = price;
            minProduct = name;
        }
    }

    file.close();

    cout << "\n=== СТАТИСТИКА ===" << endl;
    cout << "Всего товаров: " << totalQuantity << " шт." << endl;
    cout << "Общая стоимость: " << fixed << setprecision(2) << totalValue << " руб." << endl;
    cout << "Самый дорогой: " << maxProduct << " (" << maxPrice << " руб.)" << endl;
    cout << "Самый дешевый: " << minProduct << " (" << minPrice << " руб.)" << endl;

    return 0;
} 