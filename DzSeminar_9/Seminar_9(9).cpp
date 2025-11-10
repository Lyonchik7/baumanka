#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillVector(shared_ptr<vector<int>> buf) {
    for (int i = 0; i < (*buf).size(); i++) {
        (*buf)[i] = rand() % 11;
    }
}

void processA(shared_ptr<vector<int>> buf) {
    for (int i = 0; i < (*buf).size(); i++) {
        (*buf)[i] += 1;
    }
}

void processB(shared_ptr<vector<int>> buf) {
    for (int i = 0; i < (*buf).size(); i++) {
        (*buf)[i] *= 2;
    }
}

void printVector(shared_ptr<vector<int>> buf) {
    for (int num : *buf) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Введите количество элементов: ";
    cin >> N;

    srand(time(0));

    // Создаем и заполняем вектор
    auto buffer = make_shared<vector<int>>(N);
    fillVector(buffer);

    cout << "Исходный вектор: ";
    printVector(buffer);

    // Копия для processB
    auto buffer_copy = make_shared<vector<int>>(*buffer);

    // Применение processA к оригиналу
    processA(buffer);
    cout << "После processA: ";
    printVector(buffer);

    // Применение processB к копии
    processB(buffer_copy);
    cout << "После processB: ";
    printVector(buffer_copy);

    return 0;
}