#include <iostream>
#include <memory>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    unique_ptr<int> ptr = make_unique<int>();

    *ptr = 10;
    cout << "Значение: " << *ptr << endl;

    *ptr = 25;
    cout << "Новое значение: " << *ptr << endl;

    return 0;
}