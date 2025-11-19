#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int numbers[] = { 15, 23, 7, 42, 18, 91, 3, 56, 77, 10 };
    int read_numbers[10];
    int sum = 0;

    // Запись в файл
    ofstream out("numbers.bin", ios::binary);
    out.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    out.close();

    // Чтение из файла
    ifstream in("numbers.bin", ios::binary);
    in.seekg(0, ios::end);
    size_t size = in.tellg();
    in.seekg(0, ios::beg);
    in.read(reinterpret_cast<char*>(read_numbers), size);
    in.close();

    // Вывод результатов
    cout << "Размер файла: " << size << " байт" << endl;
    cout << "Числа: ";
    for (int i = 0; i < 10; i++) {
        cout << read_numbers[i] << " ";
        sum += read_numbers[i];
    }
    cout << endl << "Сумма: " << sum << endl;

    return 0;
}