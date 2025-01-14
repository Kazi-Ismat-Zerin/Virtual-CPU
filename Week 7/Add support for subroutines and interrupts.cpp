#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;

atomic<bool> interruptFlag(false);


void subroutineTask(int taskId) {
    cout << "Subroutine Task " << taskId << " started." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Subroutine Task " << taskId << " completed." << endl;
}


void interruptHandler() {
    while (true) {
        if (interruptFlag.load()) {
            cout << "Interrupt detected! Handling interrupt..." << endl;
            this_thread::sleep_for(chrono::milliseconds(200));
            cout << "Interrupt handled." << endl;
            interruptFlag.store(false);
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {

    thread interruptThread(interruptHandler);

    for (int i = 1; i <= 5; ++i) {
        subroutineTask(i);

        if (i == 3) {
            cout << "Triggering interrupt..." << endl;
            interruptFlag.store(true);
        }
    }
    interruptThread.detach();
    cout << "Main program finished." << endl;

    return 0;
}
