#include <iostream>
#include <cmath>
#include <algorithm>

/* Pass the array to the function */
bool rightAngleTri(double sides[3])
{
    if((pow(sides[0], 2) + pow(sides[1], 2)) == pow(sides[2], 2))
    {
        return true;
    }
    return false;
}

int main()
{
    double x = 0, y = 0, z = 0;
    
    std::cout << "Please enter the three values: " << std::endl;
    std::cin >> x >> y >> z;

    
    double sides[3] = {x, y, z};
    std::sort(sides, sides + 3); /* Sort the array */

    for (int i = 0; i < 3; i++) {
        std::cout << sides[i] << std::endl;
    }

    if(rightAngleTri(sides))
    {
        std::cout << "The triangle is considered a right angle triangle." << std::endl;
    }
    else
    {
        std::cout << "The triangle is not considered a right angle triangle." << std::endl;
    }
    return 0;
}