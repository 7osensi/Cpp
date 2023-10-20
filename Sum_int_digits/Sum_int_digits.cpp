#include <iostream>

int main() {
    int number; 
    std::cout << "Enter a number: ";
    std::cin >> number; /* 15 for example */

    /* Convert number to string */
    std::string numberString = std::to_string(number); 
    int sum = 0;

    // std::cout << numberString << std::endl;

    /* foreach loop 
    for (element_declaration : range_expression) {
        Loop body
    }
    */
    for (char digitChar : numberString) {
        /* '1' = 31 && '0' = 30 |>>| 31 - 30 = 1 
           '5' = 35 && '0' = 30 |>>| 35 - 30 = 30  */ 
        int digit = digitChar - '0'; 
        sum += digit;
    }

    std::cout << "The sum of the digits of " << number << " is: " << sum << std::endl;

    return 0;
}
