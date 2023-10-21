#include <iostream>
#include <cmath>
#include <algorithm>
#include <cctype>


bool searchNum (int arr[], int size, int num, int* indx)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            *indx = i;
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[5] = {55, 64, 2, 999, 87};
    int target = 0;
    int indx = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Enter a number: ";
    std::cin >> target;
    
    if(searchNum(arr, size, target, &indx)){
        std::cout << "Number " << target << " is in index " << indx << std::endl;
    }
    else{
        std::cout << "The number " << target << " was not found in the array!" << std::endl;
    }
    return 0;
}
