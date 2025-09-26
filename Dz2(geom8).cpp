#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    double x1, x2, y1, y2;

    cout <<"Первая точка (x1, y1):"<< endl;
    cin >> x1 >> y1;
    cout << "Вторая точка (x2, y2):" << endl;
    cin >> x2 >> y2;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double length = sqrt(dx * dx + dy * dy);

    cout << "Расстояние между ( " << x1 << "," << y1 << ") и ( " << x2 << "," << y2 << ") равняется   " << length;
    
    return 0;

}

