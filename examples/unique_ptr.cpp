#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <memory>

int main() {
    for (int i = 0; i < 10; i++) {
        std::make_unique<int>(10);
    }

    _CrtDumpMemoryLeaks();
    return 0;
}

//��������� unique_ptr ���������� ������, ������� ������, ����� ������ �� scope, ��� ��� ������ �������