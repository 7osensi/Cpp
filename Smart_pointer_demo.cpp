#include <iostream>
#include <memory>

using namespace std;

class UDT {
    public:
        UDT() {cout << "Defualt Constructor is called" << endl; }
        ~UDT() {cout << "Destructor is called" << endl; }
};
int main () {
    std::unique_ptr<UDT> Hussein = std::unique_ptr<UDT>(new UDT);

    // std::unique_ptr<UDT> Yomna = Hussein; //error
    return 0;
}