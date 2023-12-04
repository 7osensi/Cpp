#include <iostream>
#include <algorithm>

bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    bool allEven = std::all_of(arr, arr + size, isEven); // Check if all the returns are true

    if (allEven) {
        std::cout << "All elements in the array are even." << std::endl;
    } else {
        std::cout << "Not all elements in the array are even." << std::endl;
    }

    return 0;
}
