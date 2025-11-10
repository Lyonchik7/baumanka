#include <iostream>
#include <memory>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    shared_ptr<int> ptr1 = make_shared<int>(100);
    cout << "use_count: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr2 = ptr1;
    shared_ptr<int> ptr3 = ptr2;
    cout << "use_count: " << ptr1.use_count() << endl;

    ptr2.reset();
    cout << "use_count: " << ptr1.use_count() << endl;

    if (ptr2) {
        cout << "ptr2 работает" << endl;
    }
    else {
        cout << "ptr2 не работает" << endl;
    }

    return 0;
}