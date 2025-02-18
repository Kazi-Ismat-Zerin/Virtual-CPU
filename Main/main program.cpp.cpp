
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <bitset>

using namespace std;

// 1. Registers
struct Registers {
    int R[4] = {0}; // 4 General Purpose Registers
    int PC = 0;  // Program Counter
    int IR = 0;  // Instruction Register
};

// 2. Memory Simulation
vector<int> memory(256, 0);

// 3. I/O Device Simulation
queue<int> inputBuffer;
vector<int> outputBuffer;

void inputDevice(int value) {
    inputBuffer.push(value);
}

int outputDevice() {
    if (!outputBuffer.empty()) {
        int value = outputBuffer.back();
        outputBuffer.pop_back();
        return value;
    }
    return -1; // No output available
}

// 4. ALU Operations
int ALU(int op, int a, int b) {
    switch (op) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        case 3: return a / (b ? b : 1);
        default: return 0;
    }
}

// 5. Instruction Set
enum Instructions { ADD, SUB, MUL, DIV, LOAD, STORE, JMP, PRINT, HALT, IN, OUT };

// 6. Control Unit & Execution
void execute(vector<int>& program, Registers& reg) {
    while (true) {
        reg.IR = program[reg.PC];
        int instr = reg.IR;
        switch (instr) {
            case ADD: reg.R[0] = ALU(0, reg.R[1], reg.R[2]); break;
            case SUB: reg.R[0] = ALU(1, reg.R[1], reg.R[2]); break;
            case LOAD: reg.R[1] = memory[program[++reg.PC]]; break;
            case STORE: memory[program[++reg.PC]] = reg.R[1]; break;
            case PRINT:
                outputBuffer.push_back(reg.R[1]);
                break;
            case IN:
                if (!inputBuffer.empty()) {
                    reg.R[1] = inputBuffer.front();
                    inputBuffer.pop();
                }
                break;
            case OUT:
                outputBuffer.push_back(reg.R[1]);
                break;
            case HALT: return;
        }
        reg.PC++;
    }
}

// 7. Assembler (Convert Assembly Code to Machine Code)
vector<int> assembler(vector<string> assembly) {
    unordered_map<string, int> opcodes = {
        {"ADD", ADD}, {"SUB", SUB}, {"LOAD", LOAD}, {"STORE", STORE},
        {"PRINT", PRINT}, {"HALT", HALT}, {"IN", IN}, {"OUT", OUT}
    };
    vector<int> program;
    for (const string& line : assembly) {
        stringstream ss(line);
        string instr;
        ss >> instr;
        program.push_back(opcodes[instr]);
        int operand;
        while (ss >> operand) program.push_back(operand);
    }
    return program;
}

// 8. Utility Function - Print Output in Binary
void printBinary(int value) {
    cout << "Binary Output: " << bitset<8>(value) << endl;
}

// 9. Main Function
int main() {
    Registers reg;
    vector<string> assembly_code = { "IN", "ADD", "OUT", "HALT" };
    vector<int> program = assembler(assembly_code);

    // Simulate input
    inputDevice(10);

    execute(program, reg);

    // Retrieve output in binary
    int finalOutput = outputDevice();
    if (finalOutput != -1) {
        printBinary(finalOutput);
    } else {
        cout << "No Output Available" << endl;
    }

    return 0;
}
