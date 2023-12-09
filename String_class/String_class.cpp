    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <string>

    class String{  
        private:
            char* str; 
            int len;
        
        public:   
    
            // Default constructor
            String() : str(new char[1]), len(1) {
                std::cout << "Default Constructor" << std::endl;
                str[0] = '\0'; // Initialize the string with a null terminator
            }
            // Destructor
            ~String() { 
                delete[] str; // Deallocate the memory
            }
            //Parameters constructor 
            String(const char* copy) { 
                len = std::strlen(copy);
                str = new char[len + 1];
                std::strcpy(str, copy);
            } 
            // Copy constructor 
            String(const String& other) {
                len = other.len; 
                str = new char[len + 1];
                std::strcpy(str, other.str);
            }
            // Copy-assignment operator
            String& operator= (const String& other) {
                std::cout << "Copy-assignment operator" << std::endl;
                if(this != &other) {
                    delete [] this->str;
                    this->len = other.len;
                    str = new char[len + 1];
                    std::strcpy(this->str, other.str);
                }
                return *this;
            }

            // Move operator
            String& operator= (String&& other) {
                std::cout << "Move operator" << std::endl;
                if(this != &other) {
                    if(this->str) {
                        delete [] this->str;
                    }
                    this->len = other.len;
                    str = new char[len + 1];
                    std::strcpy(this->str, other.str);
                    other.str = nullptr;
                }
                return *this;
            }

            bool operator==(const String& other) const {
                return (this->len == other.len) && (std::strcmp(str, other.str) == 0);
            }

            // Move constructor
            // && rvalue reference
            String(String&& other) {
                std::cout << "Move constructor" << std::endl;
                if(other.str) {
                    this->str = other.str;  // Transfer ownership
                    this->len = other.len;
                    other.str = nullptr;  // Set to null to avoid double deletion
                    other.len = 0;  // Reset the length
                }
            }

            // Print the length of the string
            int printLength() const {
                return len;
            }
            // Print the string
            const char* printString() const {
                return str;
            }
            // To access the private members use friend keyword
            // output stream operator '<<' overloading
            // (eg.) std::cout << String s << std::endl;
            friend std::ostream& operator<<(std::ostream& os, const String& obj);
            
            // Equality operator overloading 
            // (eg.) if(s4 == "Hello World")
            friend bool operator==(const String& other, const char* constStr);
    };

    std::ostream& operator<<(std::ostream& os, const String& obj)
    {
        os << obj.str;
        return os;
    }

    bool operator==(const String& other, const char* constStr) {
            return (std::strcmp(constStr, other.str) == 0);
    }

    int main() {
        
        String s1("Hello");
        std::cout << "s1 length : " << 15 << std::endl;
        std::cout << "s1 string : " << s1.printString() << std::endl;
        
        std::cout << " " << std::endl;
        
        String s2("Hi");
        std::cout << "s2 length : " << s2.printLength() << std::endl;
        std::cout << "s2 string : " << s2.printString() << std::endl;

        std::cout << " " << std::endl;

        String s3("Hola");
        std::cout << "s3 length : " << s3.printLength() << std::endl;
        std::cout << "s3 string : " << s3.printString() << std::endl;
        
        std::cout << " " << std::endl;

        String s4;
        s4 = s1; // Copy-assignment '=' operator overloading
        std::cout << "s4 length : " << s4.printLength() << std::endl;
        std::cout << "s4 string : " << s4.printString() << std::endl;

        std::cout << s4 << std::endl; // << operator overloading

        if(s4 == s1) {
            std::cout << "EQUAL using s4 == s1" << std::endl;
        }

        if(s4 == "Hello") {
            std::cout << "EQUAL using s4 == \"Hello\"" << std::endl;
        }

        String s5(std::move(s3));
        std::cout << "s5 after using the move constructor " << s5.printString() << std::endl;

        String s6;
        s6 = (std::move(s1));
        std::cout << "s6 after move operator " << s6.printString() << std::endl;

        return 0;
    }