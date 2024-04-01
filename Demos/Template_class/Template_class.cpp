#include <iostream>

template<class T>

class A{
    public:
        T x = 55;
        T y = 66; 

        A(T a, T b) : x(a), y(b){}
        
        T Sum(void){ return x + y; }

};


int main(){

    A<int> obj(10, 12);
    

    std::cout << obj.Sum() << std::endl;


    return 0;
}