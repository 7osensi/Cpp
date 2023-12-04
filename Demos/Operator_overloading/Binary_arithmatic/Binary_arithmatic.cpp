#include<iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class myClass {
    private:
        double Num;

    public:
        myClass() 
        : Num{0} {}
        
        myClass(double temp) 
        : Num{temp} {}

        myClass operator+ (myClass B) {
            return this->Num + B.Num;
        }

        myClass operator- (myClass B) {
            return this->Num - B.Num;
        }

        myClass operator* (myClass B) {
            return this->Num * B.Num;
        }

        myClass operator/ (myClass B) {
            if(B.Num == 0) {
                throw runtime_error("Division by zero error");
            }
            return this->Num / B.Num;
        }

        myClass operator% (myClass B) {
            if(B.Num == 0.0) {
                throw runtime_error("Modulo by zero error");
            }
            return (fmod(this->Num , B.Num));
        }

        void display(void) {
            cout << Num << endl;
        }

};

int main() {
    myClass A{100}, B{50};
    myClass C;
    
    B = A + B; // C.operator=(A.operator+(myClass(B)));
    B.display();
    
    C = A - B;
    C.display();
    
    C = A * B;
    C.display();
    
    try {
        C = A / B;
        C.display();
    } catch (const runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        C = A % B;
        C.display();
    } catch (const runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}