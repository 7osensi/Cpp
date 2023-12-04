#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int arr[100];

    iota(begin(arr), end(arr), 10);

    for (int i = 0; i < 100; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
