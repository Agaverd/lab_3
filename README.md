# lab_3
### Leak
В первом примере явной утечки мы смогли отследить её при помощи библиотеки `#include <crtdbg.h>`. В консоль при обнаружении выводятся адреса, которым принадлежит утечка.
```
{90} normal block at 0x000001BF1B967D30, 4 bytes long.
 Data: <    > 0A 00 00 00 
 ...
 {81} normal block at 0x000001BF1B9676F0, 4 bytes long.
 Data: <    > 0A 00 00 00 
Object dump complete.
```


### std::unique_ptr
###### Просто пример
Второй пример показывает, как можно избежать утечек памяти при помощи `std::unique_ptr`. В этом случае память освобождается автоматически, когда объект выходит из области видимости. 

###### Посложнее
Реализован класс для псевдо-работы с файлом, и продемонстривано удаление его манульно и автоматически.
```private:
    struct FileCloser {
        void operator()(FILE* file_ptr) const {
            if (file_ptr) {
                std::fclose(file_ptr);
            }
        }
    };
```
_private секция класса 'FileManager'_

    std::unique_ptr<FILE, FileCloser> file_handle;
    std::string filename;

### std::shared_ptr
Реализован класс популяции мышей, через который мы можем отслеживать их количество.
```
struct Rat {
    int length;
    Rat(int value) : length(value) {
        std::cout << "Rat born" << std::endl;
    }

    ~Rat() {
        std::cout << "Rat destroyed :(" << std::endl;
    }
};
```
Проведены тесты с выходом за пределы области видимости.

### std::weak_ptr
Примитивный пример использования `std::weak_ptr` для отслеживания объекта, который может быть удалён.