#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    int x = 5, y = 10;
    int* p1 = &x;
    int* p2 = &y;
    cout << "До замены указателей:" << endl;
    cout << "Переменная x = " << *p1 << "; её адрес: " << p1 << endl;
    cout << "Переменная y = " << *p2 << "; её адрес: " << p2 << endl;
    
    void swapPointers(int** p1, int** p2);
    cout << "\nПосле замены указателей:" << endl;
    cout << "Переменная x = " << *p2 << "; её адрес: " << p2 << endl;
    cout << "Переменная y = " << *p1 << "; её адрес: " << p1 << endl;
        
    return 0;
}

