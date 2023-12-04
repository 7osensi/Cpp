#include <iostream>
#include <cctype>

int main() {
    char c;
    std::cout << "Enter a character: ";
    std::cin >> c;
    if(std::isdigit(c)){
        std::cout << "Character " << c << " is a number." << std::endl;
    }
    else{
        std::cout << "Character " << c << " is not a number." << std::endl;
    }
    return 0;
}
