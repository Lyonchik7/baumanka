#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<string> routes = {
        "London-Paris",
        "Paris-Berlin",
        "Berlin-Warsaw",
        "Warsaw-Kiev",
        "Kiev-Moscow"
    };

    shared_ptr<vector<string>> ptrRoutes = make_shared<vector<string>>(routes);

    auto countCity = [](shared_ptr<vector<string>> routesPtr, const string& city) -> int {
        int count = 0;
        for (const auto& route : *routesPtr) {
            if (route.find(city) != string::npos) {
                count++;
            }
        }
        return count;
        };

    auto sortByLength = [](shared_ptr<vector<string>> routesPtr) {
        sort(routesPtr->begin(), routesPtr->end(),
            [](const string& a, const string& b) {
                return a.length() > b.length();
            });
        };

    auto concat = [](shared_ptr<vector<string>> routesPtr) -> string {
        if (routesPtr->empty()) {
            return "";
        }

        string result;
        for (size_t i = 0; i < routesPtr->size(); ++i) {
            result += (*routesPtr)[i];
            if (i != routesPtr->size() - 1) {
                result += " ";
            }
        }
        return result;
        };

    int parisCount = countCity(ptrRoutes, "Paris");
    cout << "Количество маршрутов с Paris: " << parisCount << endl;

    int berlinCount = countCity(ptrRoutes, "Berlin");
    cout << "Количество маршрутов с Berlin: " << berlinCount << endl;

    cout << "\nДо сортировки:" << endl;
    for (const auto& route : *ptrRoutes) {
        cout << route << " (длина: " << route.length() << ")" << endl;
    }

    sortByLength(ptrRoutes);

    cout << "\nПосле сортировки по убыванию длины:" << endl;
    for (const auto& route : *ptrRoutes) {
        cout << route << " (длина: " << route.length() << ")" << endl;
    }

    string combinedRoutes = concat(ptrRoutes);
    cout << "\nОбъединенная строка маршрутов:" << endl;
    cout << combinedRoutes << endl;

    return 0;
}