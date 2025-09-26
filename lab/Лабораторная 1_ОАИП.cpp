#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    const int size = 10;
    int nums[size];

    for (int i = 0; i < size; i++) {
        cout << "Введите число" << i + 1 << ":";
        cin >> nums[i];

    }

    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";

    }

    int summa = 0;
    int max = nums[0];

    for (int i = 0; i < size; i++) {
        summa += nums[i];
        if (max < nums[i])
            max = nums[i];
    }

    cout << "Сумма всех элементов:" << summa << endl;
    cout << "Максимальный элемент:" << max << endl;


    void bubbleSort(int nums[], int size); {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (nums[j] < nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;

                }
            }
        }

    }

    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";

    }

    return 0;
}
