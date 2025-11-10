#include <iostream>
#include <memory>

using namespace std;

// Функция создает массив и возвращает unique_ptr
unique_ptr<int[]> createArray(int n) {
    auto arr = make_unique<int[]>(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  
    }
    return arr; 
}

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    
    // Получаем массив из функции
    auto array = createArray(n);
    
    // Выводим элементы
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
