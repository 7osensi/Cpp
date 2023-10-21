#include <iostream>
#include <algorithm>

int main()
{
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);


    // Sort the array in ascending order
    /* The third parameter(optional) comp has to be a function that determines 
       the order in which the elements are going to be sorted. */
    std::sort(arr, arr + size, [](int a, int b) {
        return a < b;
    });

    std::cout << "Array sorted in ascending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Sort the array in descending order
    std::sort(arr, arr + size, [](int a, int b) {
        return a > b;
    });

    std::cout << "Array sorted in descending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}