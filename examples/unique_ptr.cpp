#include <iostream>
#include <memory>

int main() {
    for (int i = 0; i < 10; i++) {
        std::make_unique<int>(10);
    }
    return 0;
}

//указатель unique_ptr уничтожает объект, которым владел, после выхода из scope, так что память очищена