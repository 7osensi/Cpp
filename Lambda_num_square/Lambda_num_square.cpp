#include <iostream>
#include <algorithm>

int main()
{
    int number = 0;

    std::cout << "Enter a number: ";
    std::cin >> number;

    auto square = [](int number) -> int
    {
        return number * number;
    };
    
    int result = square(number);
    std::cout << "The square of " << number << " is: " << result << std::endl;

    return 0;
}
