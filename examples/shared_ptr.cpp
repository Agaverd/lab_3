#include <iostream>
#include <memory>

struct Data {
    int value;
    Data(int v) : value(v) {}
};

int main() {
    std::shared_ptr<Data> ptr1 = std::make_shared<Data>(10);
    {
        std::shared_ptr<Data> ptr2 = ptr1;
        std::cout << "Conuter inside: " << ptr1.use_count() << std::endl;
    }
    std::cout << "Conuter outside: " << ptr1.use_count() << std::endl;
    return 0;
}

//shared_ptr ��������� ����� ������� ����� � ��� �� ��������.
//����� ��������� ������� ���������� ����������, ������� ��� �� ��������� �� ���� ������.
//��� �� shared_ptr ������� ������, ����� ��������� ��������� ptr, ����������� �� ����.