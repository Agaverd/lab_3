#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>

int main() {
    for (int i = 0; i < 10; i++) {
        int* ptr = new int(10);
    }

    _CrtDumpMemoryLeaks();
    return 0;
}

// не вызвали delete дл€ ptr - имеем утечку пам€ти
// см. вывод/отладка