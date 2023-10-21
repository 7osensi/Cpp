#include <iostream>
#include <algorithm>
#include <cctype>

void delete_Element (int arr[], int &size, int index)
{
    if (index < 0 || index >= size) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    // Use std::remove to shift the elements to be deleted to the end of the array
    std::remove(arr, arr + size, arr[index]);

    // Decrement the size of the array
    size--;
}

int main()
{

    int arr[5] = {55, 54, 648, 11, 66};
    int index = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before deletion: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete_Element(arr, size, index);

    std::cout << "After deletion: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
