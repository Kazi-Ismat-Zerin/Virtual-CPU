#include <iostream>
using namespace std;

// Simulated CPU class
class CPU {
public:
    void processInput(int input) {
        cout << "CPU processing input: " << input << endl;
    }

    void sendOutput(int output) {
        cout << "CPU sending output: " << output << endl;
    }
};

// Main function to demonstrate I/O integration
int main() {
    CPU cpu;

    int userInput;
    cout << "Enter a number: ";
    cin >> userInput; // Input operation

    cpu.processInput(userInput); // Process input

    int processedOutput = userInput * 2; // Simple processing
    cpu.sendOutput(processedOutput); // Output operation

    return 0;
}
