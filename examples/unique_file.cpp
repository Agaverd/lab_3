#include <cstdio>    
#include <memory>    
#include <string>    
#include <iostream> 

class FileManager {
public:
    FileManager(const std::string& fname, const std::string& mode) : 
        filename(fname) {
        FILE* file_ptr = std::fopen(filename.c_str(), mode.c_str());
        file_handle.reset(file_ptr);

        if (!file_handle) {
            std::cerr << "Error: Could not open file " << filename << "\n";
        }
        else {
            std::cout << "File " << filename << " opened successfully.\n";
        }
    }

    ~FileManager() {
        std::cout << "FileManager for " << filename << " being destroyed.\n";
        //Not neccessary to manually delete data
        //unique_ptr will do the whole deal by himself
    }


    [[nodiscard]] bool is_open() const {
        return file_handle != nullptr;
    }

    void close() {
        file_handle.reset(nullptr);
    }

private:
    struct FileCloser {
        void operator()(FILE* file_ptr) const {
            if (file_ptr) {
                std::fclose(file_ptr);
            }
        }
    };

    std::unique_ptr<FILE, FileCloser> file_handle;
    std::string filename;

};

int main() {
    //test with leaving scope
    std::cout << "Test 1 | Scope\n\t Enter to scope\n";
    {
        FileManager file_1("example.txt", "w"); 

        if (file_1.is_open()) {
            std::cout << "File opened successefully\n";
        }
        std::cout << "\t Exit out of scope\n\n";
    }

    //Use manual closing
    std::cout << "\nTest 2 | Manual Closing\n";
    FileManager file_2("example.txt", "w");
    file_2.close();

    std::cout << "Exiting main. File example3.txt should be closed automatically by file4's destructor.\n";
    return 0;
}
