#include <iostream>
#include <bitset>

int main() {
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    std::bitset<32> binary(decimalNumber);

    std::string binaryStr = binary.to_string();

    std::cout << "Binary representation: " << binaryStr << std::endl;

    /*******************************************************/

    std::string binaryString;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryString;

    std::bitset<32> bin(binaryString);
    unsigned long decimalNum = bin.to_ulong();

    std::cout << "Decimal representation: " << decimalNum << std::endl;

    return 0;
}
