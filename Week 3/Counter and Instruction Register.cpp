#include <iostream>
using namespace std;

class CPU {
private:
    int pc;
    string ir;
    string memory[3];

public:

    CPU() : pc(0), ir("") {
        memory[0] = "ADD";    // Instruction at memory[0]
        memory[1] = "SUB";    // Instruction at memory[1]
        memory[2] = "HALT";   // Instruction at memory[2]
    }
    void fetch() {
        ir = memory[pc];
        cout << "Fetched instruction: " << ir << " at address " << pc << endl;
    }
    void execute() {
        if (ir == "ADD") {
            cout << "Executing ADD operation." << endl;
        } else if (ir == "SUB") {
            cout << "Executing SUB operation." << endl;
        } else if (ir == "HALT") {
            cout << "HALT operation. Stopping execution." << endl;
        }
    }
    void run() {
        while (pc < 3) {
            fetch();    // Fetch the instruction
            execute();  // Execute the instruction
            pc++;       // Increment the Program Counter to the next instruction
        }
    }
};

int main() {
    CPU cpu;   // Create a CPU object
    cpu.run(); // Start the CPU and run the instructions
    return 0;
}
