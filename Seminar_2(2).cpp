#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    float d;
    float e;
    cout << "Ведите длину прямоугольника" << endl;
    cin >> d;
    cout << "Ведите ширину прямоугольника " << endl;
    cin >> e;
    cout << " Площадь равна: " << d * e << endl;

    return 0;
}