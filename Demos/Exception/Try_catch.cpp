#include <bits/stdc++.h>

using namespace std;

double div(double a, double b){

    if(b == 0){
        throw std::runtime_error("Division by zero error");
    }
    return a / b;
}

int main(){

double x = 5.0, y = 0.0;
double res = 0;

try{
    res = div(x, y);
} catch(const std::runtime_error& e){
    std::cerr << "Caught a runtime error: " << e.what() << std::endl; // e.what() prints error text
}

// std::unique_ptr<int> uptr;
// auto p = uptr;

auto p1 = make_unique<int>(10);

return 0;

}