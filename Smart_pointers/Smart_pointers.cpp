#include <iostream>
#include <memory>

class UDT{
    public:
        UDT(){ std::cout << "UDT Created" << std::endl; }

        ~UDT(){ std::cout << "UDT Destroyed" << std::endl; }
};

int main(){
    std::shared_ptr<UDT> ShPtr1 = std::make_shared<UDT>();
    std::shared_ptr<UDT> ShPtr2 = ShPtr1;

    std::cout << "Use count = " << ShPtr1.use_count() << std::endl;
    return 0;
}