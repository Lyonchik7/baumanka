#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Command {
    string name;
    int value;
};

void parseCommand(const char* input, vector<Command>& commands) {
    const char* p = input;
    Command cmd;
    cmd.value = 0;

    // Читаем название команды
    while (*p != ' ' && *p != '\0') {
        cmd.name += *p;
        p++;
    }

    // Читаем число если есть
    if (*p == ' ') {
        p++;
        while (*p >= '0' && *p <= '9') {
            cmd.value = cmd.value * 10 + (*p - '0');
            p++;
        }
    }

    commands.push_back(cmd);
}

int main() {
    setlocale(LC_ALL, "RU");
    const int n = 20;
    
    vector<Command> commands;
    char input[n];

    cout << "Введите команду: ";
    cin.getline(input, n);
    parseCommand(input, commands);

    for (int i = 0; i < commands.size(); i++) {
        cout << "Команда: " << commands[i].name << ", Значение: " << commands[i].value << endl;
    }

    return 0;
}