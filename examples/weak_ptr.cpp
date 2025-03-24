#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> shared = std::make_shared<int>(10);
    std::weak_ptr<int> weak = shared; //создаём "наблюдателя"

    //lock(), если указатель !expired возвращает сам объект
    if (auto temp = weak.lock()) {
        std::cout << "Object: " << *temp << std::endl;
    }
    else {
        std::cout << "Object expired" << std::endl;
    }

    shared.reset();
    std::cout << "Object " << (weak.expired() ? "expired" : "alive") << std::endl;
    return 0;
}