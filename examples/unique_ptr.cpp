#include <iostream>
#include <memory>

int main() {
    for (int i = 0; i < 10; i++) {
        std::make_unique<int>(10);
    }
    return 0;
}

//��������� unique_ptr ���������� ������, ������� ������, ����� ������ �� scope, ��� ��� ������ �������