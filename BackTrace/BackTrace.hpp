#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class BackTrace {
    private:
        std::vector<std::string> trace;

    public:
        void addTrace(const string& Name) { 
            trace.push_back(Name);
        }

        void PrintTrace() {
            cout << "Backtrace:" << endl;
            for(const auto& functionName : trace) {
                cout << "- " << functionName << endl;
            }
        }
};

void fun2(BackTrace& backtrace);
void fun3(BackTrace& backtrace);

#define EnterFn(backtrace) \
    backtrace.addTrace("Entering " + std::string(__PRETTY_FUNCTION__)); 

#define ExitFn(backtrace) \
    backtrace.addTrace("Exiting " + std::string(__PRETTY_FUNCTION__)); 

#endif // BACKTRACE_HPP