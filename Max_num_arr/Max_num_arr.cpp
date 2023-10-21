#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>

int* max_num(int arr[], int size)
{
    /* Find the maximum element in the array */
    int* maxElement = std::max_element(arr, arr + size);
    return maxElement;
}

int main()
{
    int arr[5] = {56, 1, 120, 99, 9};
    int* max = max_num(arr, (sizeof(arr) / sizeof(arr[0])) );
    std::cout << "The maximum element in the array is: " << *max << std::endl;
    return 0;
}