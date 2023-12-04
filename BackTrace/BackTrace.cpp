#include "BackTrace.hpp"


void fun2(BackTrace& backtrace);
void fun3(BackTrace& backtrace);

void fun1(BackTrace& backtrace) { 
    EnterFn(backtrace)
    fun2(backtrace);
    ExitFn(backtrace)
}

void fun2(BackTrace& backtrace) { 
    EnterFn(backtrace)
    fun3(backtrace);
    ExitFn(backtrace)
}

void fun3(BackTrace& backtrace) { 
    EnterFn(backtrace)
    ExitFn(backtrace)
}

int main() {
    BackTrace b;
    fun1(b);
    b.PrintTrace(); 
    return 0;
}