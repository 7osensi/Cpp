#include <iostream>
#include "calc.hpp"
#include "wifi.hpp"
#include "defaultconfig.h"

int main(){
    wifi_init();
    std::cout << PRODUCT_TYPE << std::endl;
    std::cout << PRODUCT_YEAR << std::endl;
    std::cout << STD_CXX << std::endl;
    return 0;
}