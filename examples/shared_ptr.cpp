#include <iostream>
#include <memory>

struct Rat {
    int length;
    Rat(int value) : length(value) {
        std::cout << "Rat born" << std::endl;
    }

    ~Rat() {
        std::cout << "Rat destroyed :(" << std::endl;
    }
};

int main() {
		std::shared_ptr<Rat> rat1 = std::make_shared<Rat>(10);
        {
			std::shared_ptr<Rat> rat2 = rat1;
            std::cout << rat1.use_count() << " rat(s) alive" << std::endl; //����� �������� ������...
        }
		std::cout << rat1.use_count() << " rat(s) alive" << std::endl;
    return 0;
}
//��� ������ �� scope ������������ ������ ��������� �� ������
//���� ������ �� main ������ � ������ ���������� ������������ � ��� ������