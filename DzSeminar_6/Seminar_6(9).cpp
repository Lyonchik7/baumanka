#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    char str1[100], str2[100];

    cout << "Первая строка (англ): ";
    cin.getline(str1, 100);

    cout << "Вторая строка (англ): ";
    cin.getline(str2, 100);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[100][100] = { 0 };
    int maxLen = 0;
    int endIndex = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    if (maxLen > 0) {
        cout << "Результат: ";
        for (int i = endIndex - maxLen + 1; i <= endIndex; i++) {
            cout << str1[i];
        }
        cout << endl;
    }
    else {
        cout << "Нет общей подстроки" << endl;
    }

    return 0;
}