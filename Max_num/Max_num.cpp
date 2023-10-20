#include <iostream>
#include <algorithm>


#if 0
int main() {

    int num1 = 55, num2 = 88, num3 = 77;

    int max = num1;

    if(num2 > max)
    {
        max = num2;
    }
    if(num3 > max)
    {
        max = num3;
    }
    std::cout << "The max between num1, num2, and num3 : " << max << std::endl;
    return 0;
}
#endif

#if 0
int main() {

    int nums[3] = {55, 66, 77};

    int max = nums[0];

    for (int i = 1; i < 3; i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    std::cout << "The max between num1, num2, and num3 : " << max << std::endl;
    return 0;
}
#endif

#if 1
int main() {

    int x, y, z;

    x = y = z = 0;

    std::cout << "Please enter three values: " << std::endl; 

    std::cin >> x >> y >>z;

    int maxNumber = std::max({x, y, z});

    std::cout << "The max between num1, num2, and num3 : " << maxNumber << std::endl;
    return 0;
}
#endif