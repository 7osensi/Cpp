#include <iostream>

int main() {
    int multi;

    while(1)
    {
        // Input the multiplication table you wish to show 
        std::cout << "Enter the multiplication table: ";
        std::cin >> multi;

        /* Generate and display the multiplication table */
        for (int j = 1; j <= 12; j++) {
            std::cout << multi * j << "\t";
        }
        std::cout << std::endl;

    }
    return 0;
}
