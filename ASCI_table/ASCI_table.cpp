#include <iostream>

int main()
{
    std::cout << "ASCII Table from 0 to 127: " << std::endl ;
    std::cout << ":::::::::::::::::::::::::::::::" << std::endl ;

    for (int i = 0; i <= 127 ; i++)
    {
       if (i < 32) {
            std::cout << "ASCII code: " << i << " || Char: [Non-Printable]" << std::endl;
        } else {
            std::cout << "ASCII code: " << i << " || Char: " << static_cast<char>(i) << std::endl;
        }
    }
    return 0;
}
