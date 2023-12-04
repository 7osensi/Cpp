#if 0

#include <iostream>

using namespace std;

class myClass{
    private:
    unsigned int count;

    public:
    myClass() : count{0} //default constructor
    {}

    myClass(unsigned int c) : count{c} 
    {}
    /* Prefix */
    myClass operator ++() {
        ++count;
        return myClass(count);
    }
    /* Prefix */
    myClass operator --() {
        --count;
        return myClass(count);
    }

    /* Postfix */
    myClass operator ++(int) {
        count++;
        return myClass(count);
    }
    /* Postfix */
    myClass operator --(int) {
        count--;
        return myClass(count);
    }

    unsigned int get_count(){
        return count;
    }

};

int main() {
    myClass s1{5};
    myClass s2{10};
    myClass s3 = ++s1;
    myClass s4 = --s2;

    cout << s3.get_count() << endl;
    cout << s4.get_count() << endl;
}
#endif

#if 0

#include <iostream>

using namespace std;

class Distance{
    private:
        int feet;
        int inches;
    public:
        Distance() 
        : feet(0), inches(0)
        {
        }
        Distance(int f, int i) 
        : feet(f), inches(i)
        { 
        }
        Distance operator + (Distance d2) {
            int f = feet + d2.feet;
            int i = inches + d2.inches;

            return (Distance(f, i));
        }

        Distance operator - (Distance d2) {
            int f = feet - d2.feet;
            int i = inches - d2.inches;

            return (Distance(f, i));
        }

        void printDistance(){
            cout << "Feet " << feet << endl;
            cout << "Inches " << inches << endl;
        }
};

int main() {
    Distance d1{50, 50}, d2(100, 100);
    Distance d3 = d1 + d2;
    d3.printDistance();
    return 0;
}

#endif

#if 0
#include <iostream>

using namespace std;

class Complex{
    private:
        int real;
        float img;
    public:
        int result1{0};
        int result2{0};

        Complex() 
        : real(0), img(0)
        {}

        Complex(int r, float i) 
        : real(r), img(i)
        {}

        int operator + (int real) {
            return (this->real + real);
        }

        float operator + (float img) {
            return (this->img + img);
        }

        Complex operator + (const Complex& B) {
            Complex result;
            result.real = B.real + real;
            result.img = B.img + img;
            return result;
        }

        int operator ()(int num) {
            return real++;
        }

        int normalFunc (int num) {
            return real++;
        }

        void printNum(){
            cout << real << endl;
            cout << img << endl;
        }
};

int main() {
    // Complex N1{50, 50.5}, N2(100, 100.100);
    
    // int real = N1 + 50;
    // cout << real << endl;
    
    // float img = N2 + 100.100f;
    // cout << img << endl;
    
    // Complex N3{};
    // N3 = N1 + N2;
    // N3.printNum();

    Complex N4{60, 60.6};
    cout << N4(10) << endl;
    cout << N4(10) << endl;
    cout << N4(10) << endl;

    Complex N5{70, 70.7};
    cout << N5.normalFunc(10) << endl;
    cout << N5.normalFunc(10) << endl;
    cout << N5.normalFunc(10) << endl;

    return 0;
}
#endif

#if 1

#include <iostream>
 
using namespace std;

class MyClass {
    private:
        int* data;

    public:
        MyClass() {
            data = new int[5];
            for(int i = 0; i < 5; i++) {
                data[i] = i * i;
            }
        }

        ~MyClass() {
            delete[] data;
        }

        void PrintingData() {
            for(int i = 0; i < 5; i++) {
                cout << data[i] << endl;
            }
        }

        void SetData(int index, int value) {
            data[index] = value;
        }
};

int main() {
    MyClass myclass1;
    myclass1.PrintingData();
    return 0;
}

#endif