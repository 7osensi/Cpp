#include <iostream>
#include <map>

int main(){
    std::map<int, std::string> m;
 
    m.insert({2, "Hussein"});
    m.emplace(1, "Mahmoud");
    
    m[1] = "Aly";
   
    auto x = m.find(2);
    auto i = m.begin();
    
    // std::cout << i->first << "  " << i->second << std::endl;
    // std::cout << x->first << "  " << x->second << std::endl;

    for(auto element : m) { std::cout << "Key " << element.first << " Value " << element.second << std::endl; }

    int o = 10;
    auto geto = [o]{return o;};
    std::cout << o << std::endl;
 
    return 0;
}   