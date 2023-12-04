#include <iostream>
#include <csignal>
#include <cstdlib>

using namespace std;

// Signal handler function
void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received." << endl;

    // Terminate program
    exit(signum);
}

int main() {
    // Register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);

    // Infinite loop
    while (1) {
        cout << "Running..." << endl;
        sleep(1);
        // Simulate some work
    }

    return 0;
}
