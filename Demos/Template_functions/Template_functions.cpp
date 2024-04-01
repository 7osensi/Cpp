#include <iostream>

template<typename T>
T Sum(T a, T b){ return a + b; }

int main(){
    
    std::cout << Sum(5.5, 7.5) << std::endl;

    return 0;
}