#include <iostream>
#include <algorithm>

int main()
{
    int arr1[] = {1, 2, 13, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int mergedSize = size1 + size2;
    
    int mergedArr[mergedSize];

    // std::cout << arr1 << "\t";
    // std::cout << size1 + arr1 << "\t";
    // std::cout << mergedArr << "\t";
    
    std::copy(arr1, size1 + arr1,mergedArr);
    std::copy(arr2, size2 + arr2,mergedArr + size1);

    for(int i = 0; i < mergedSize; i++)
    {
        std::cout << mergedArr[i] << "\t";
    }
    std::cout << std::endl;
    return 0;
}
