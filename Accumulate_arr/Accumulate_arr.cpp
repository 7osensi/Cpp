#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int arr[] = {55, 66, 77, 88, 99};

    int sum = accumulate(begin(arr), end(arr), 0);
    std::cout << sum<< std::endl;
    return 0;
}
