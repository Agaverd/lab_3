#include <iostream>

int main() {
    for (int i = 0; i < 10; i++) {
        int* ptr = new int(10);
    }
    return 0;
}

//не вызывается delete после выделения памяти