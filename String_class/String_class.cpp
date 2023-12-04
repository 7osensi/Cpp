#include <iostream>
#include <algorithm>
#include <cstring>

class strr{
    
private:

    char* str_; 
    int len;
    
public:

    static int x;
    
    strr() : str_(new char[1]), len(1) {
        str_[0] = '\0'; // Initialize the string with a null terminator
    }

    ~strr() { /* Destructor */
        delete[] str_; /* deallocate the memory */
    }

    strr(const char* string){ /* Parameters constructor */
        len = std::strlen(string);
        str_ = new char[len + 1]; /* allocate a byte in the heap */
        std::strcpy(str_, string);
    } 

    int getLength() const {
        return len;
    }

    const char* getString() const {
        return str_;
    }
};

int strr::x = 15;

int main() {
    
    strr s1("Nihal");
    std::cout << s1.getLength() << std::endl;
    std::cout << s1.getString() << std::endl;
    
    strr s2("Hussein");
    std::cout << s2.getLength() << std::endl;
    std::cout << s2.getString() << std::endl;

    strr s3("Mahmoud");
    std::cout << s3.getLength() << std::endl;
    std::cout << s3.getString() << std::endl;
    std::cout << std::endl;  
    std::cout << strr::x << std::endl;

    return 0;
}