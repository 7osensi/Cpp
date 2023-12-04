#include <iostream>
#include <algorithm>

bool isEven(int arr[], int size) {
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            return true;
        }
    }
    return false;
}

int main() {
    int arr1[] = {2, 4, 6, 8, 10}; 
    int arr2[] = {11, 15, 55, 9, 19}; 

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "array1" << std::endl;
    if (isEven(arr1, size1)) {
        std::cout << "There is an even element in the array." << std::endl;
    } else {
        std::cout << "There is not a single even element in the array." << std::endl;
    }
    
    
    std::cout << "array2" << std::endl;
    if (isEven(arr2, size2)) {
        std::cout << "There is an even element in the array." << std::endl;
    } else {
        std::cout << "There is not a single even element in the array." << std::endl;
    }
    return 0;
}