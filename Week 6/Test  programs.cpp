#include <iostream>
#include <string>
using namespace std;
string keyboardInput() {
    string input;
    cout << "[Keyboard] Enter input: ";
    getline(cin, input);
    return input;
}

void displayOutput(const string &output) {
    cout << "[Display] " << output << endl;
}

class CPU {
public:
    void execute() {
        cout << "[CPU] Starting execution..." << endl;

        string input = keyboardInput();

        string processedInput;
        for (char c : input) {
            processedInput += toupper(c);
        }
        displayOutput(processedInput);
        cout << "[CPU] Execution finished." << endl;
    }
};
int main() {
    CPU cpu;
    cpu.execute();
    return 0;
}
