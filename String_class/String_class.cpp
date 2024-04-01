    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <string>

    class String{  
        private:
            char* str; 
            int len;
        
        public:   
    
            // Default Constructor
            String() : str(new char[1]), len(1){
                std::cout << "Default Constructor" << std::endl;
                str[0] = '\0'; // Initialize the string with a null terminator
            }
            // Destructor
            ~String(){ delete[] str; } // Deallocate the memory
            
            // Parametarized constructor 
            String(const char* copy){ 
                std::cout << "Parametarized Constructor" << std::endl;
                len = std::strlen(copy);
                str = new char[len + 1];
                std::strcpy(str, copy);
            } 
            // Copy constructor 
            String(const String& other){
                std::cout << "Copy Constructor" << std::endl;
                this->len = other.len; 
                this->str = new char[len + 1];
                std::strcpy(str, other.str);
            }
            // Copy-assignment operator
            String& operator= (const String& other){
                std::cout << "Copy-assignment operator" << std::endl;
                if(this != &other){
                    delete [] this->str;
                    this->len = other.len;
                    str = new char[len + 1];
                    std::strcpy(this->str, other.str);
                }
                return *this;
            }

            // Move constructor
            // && rvalue reference
            String(String&& other){
                std::cout << "Move constructor" << std::endl;
                if(other.str){
                    this->str = other.str;  // Transfer ownership
                    this->len = other.len;
                    other.str = nullptr;  // Set to null to avoid double deletion
                    other.len = 0;  // Reset the length
                }
            }

            // Move-assignment operator
            String& operator= (String&& other){
                std::cout << "Move-assignment operator" << std::endl;
                if(this != &other){
                    delete[] this->str;
                    len = other.len;
                    str = new char[len + 1];
                    std::strcpy(str, other.str);
                    delete[] other.str;
                    other.str = nullptr;
                }
                return *this;
            }

            bool operator==(const String& other) const{
                return (this->len == other.len) && (std::strcmp(str, other.str) == 0);
            }
            // Operator [] accesses the specified character
            char operator[](int pos) const{
                if(pos < 0 || pos >= this->len){
                    throw std::out_of_range("Index out of bounds");
                }
                return *(this->str + pos);
            }
            // at method that returns the specified character
            char& at(int pos){
                if (pos < 0 || pos >= len){ throw std::out_of_range("String::at"); }

                return str[pos];
            }
            // true if the string is empty, false otherwise
            bool empty(void){
                if(len == 0) { return true; }
                else{ return false; }
            }

            // assign the string with char ch using count
            void assign(int count, char ch){
                std::cout << "assign method1" << std::endl;
                delete [] this->str;
                this->len = count;
                str = new char[len + 1];
                // assign the string with the char
                for(int i = 0; i < count; i++){
                    str[i] = ch;
                }
            }
            
            // assign string with another string 
            void assign(const String& other){
                std::cout << "assign method2" << std::endl;
                if(this != &other){
                    delete [] this->str;
                    this->len = other.len;
                    str = new char[len + 1];
                    std::strcpy(this->str, other.str);
                }                
            }

            // Iterator for the beginning of the string
            char* begin() { return str; }

            // Iterator for the end of the string
            char* end() { return str + len; }

            // Print the length of the string
            int printLength() const{ return len; }
            
            // Print the string
            const char* printString() const{ return str; }

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
        
        String s1; // Default constructor 
        String temp = "Hussein";
        s1 = temp;
        // std::cout << s1.printString() << std::endl;       
        
        // String s2("Bob"); // Parametarized constructor : s2 = Bob

        // String s3(s2); // Copy constructor : s3 = Bob
        
        String s4("James");
        // String s5; 
        // s5 = s4; // Copy-assigment operator : s5 = James

        // String s6("Sam");
        // String s7(std::move(s6)); // Move Operator : s7 = Sam & s6 resources are stolen

        // String s8("George");
        // String s9;
        // s9 = (std::move(s8)); // Move Operator : s9 = George & s8 resources are stolen

        // std::cout << s2 << std::endl; // '<<' Operator : Bob

        // std::cout << std::endl;

        // String s4;
        // s4 = s1; // Copy-assignment '=' operator overloading
        // std::cout << s4 << std::endl; // << operator overloading
        // std::cout << "s4 length : " << s4.printLength() << std::endl;
        // std::cout << "s4 string : " << s4.printString() << std::endl;

        // std::cout << std::endl; // newline

        // if(s4 == s1) {
        //     std::cout << "EQUAL  s4 == s1" << std::endl;
        // }

        // if(s4 == "Tom") {
        //     std::cout << "EQUAL using s4 == \"Tom\"" << std::endl;
        // }

        // std::cout << std::endl;

        // String s5(std::move(s3));
        // std::cout << "s5 after using the move constructor " << s5.printString() << std::endl;

        // std::cout << std::endl;

        // String s6;
        // s6 = (std::move(s1));
        // std::cout << "s6 after move assignment operator " << s6.printString() << std::endl;
        
        // std::cout << std::endl;

        // String s7 = "Rose";
        // std::cout << "at() : " << s7.at(2) << std::endl;
        // std::cout << "empty() : " << s7.empty() << std::endl;

        // std::cout << std::endl;

        // String s8;
        // s8.assign(4, '=');
        // std::cout << s8 << std::endl; // "===="

        // std::cout << std::endl;
        
        // String s9("Exemplary");
        // s8.assign(s9);
        // std::cout << s8 << " == " << s9 << std::endl; // "Exemplary == Exemplary"

        // std::cout << std::endl;

        // String s10("Good");
        // std::cout << " [] " << s10[1] << std::endl; 

        // std::cout << std::endl;

        // String s11("Tree");
        // std::cout << "begin " << s11 << std::endl;
        // *s11.begin() = 't';
        // std::cout << "begin " << s11 << std::endl;
        // std::cout << "end " << s11.end() << std::endl;

        // std::cout << std::endl;

        return 0;
    }