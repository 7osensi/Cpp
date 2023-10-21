#include <iostream>
#include <algorithm>

int main()
{
    int arr[] = {51, 22, 548, 62, 69, 0};
    int size = sizeof(arr) / sizeof(arr[0]); 
    
    for(int element : arr)
    {
        if(element % 2 == 0)
        {
            std::cout << element << " is even." << std::endl;
        }
        else
        {
            std::cout << element << " is odd." << std::endl;
        }
    }

    return 0;
}
