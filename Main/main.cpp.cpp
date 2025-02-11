
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <bitset>
#include <sstream>

using namespace std;

// CPU Constants
#define MEMORY_SIZE 256  // Memory size in bytes
#define NUM_REGISTERS 4  // Number of general-purpose registers

// Instruction Set
enum Instruction {
    NOP  = 0x00, // No operation
    LOAD = 0x01, // Load value into register
    STORE= 0x02, // Store register value into memory
    ADD  = 0x03, // Add two registers
    SUB  = 0x04, // Subtract two registers
    JMP  = 0x05, // Jump to an address
    IN   = 0x06, // Take input from user into register
    OUT  = 0x07, // Print register value in binary format
    HLT  = 0xFF  // Halt execution
};

// CPU Structure
class VirtualCPU {
private:
    uint8_t memory[MEMORY_SIZE] = {0};   // Memory array
    uint8_t registers[NUM_REGISTERS] = {0}; // General-purpose registers
    uint8_t PC = 0;  // Program Counter
    bool running = true;

    // Function to get binary input from the user
    uint8_t getBinaryInput() {
        string binaryStr;
        cout << "Enter 8-bit binary number: ";
        cin >> binaryStr;
        return static_cast<uint8_t>(bitset<8>(binaryStr).to_ulong());
    }

public:
    void loadProgram(vector<uint8_t> program) {
        for (size_t i = 0; i < program.size() && i < MEMORY_SIZE; i++) {
            memory[i] = program[i];
        }
    }

    void execute() {
        while (running) {
            uint8_t opcode = memory[PC++];
            switch (opcode) {
                case NOP:
                    break;
                case LOAD: {  // LOAD reg, value
                    uint8_t reg = memory[PC++];
                    uint8_t value = memory[PC++];
                    registers[reg] = value;
                    break;
                }
                case STORE: { // STORE reg, address
                    uint8_t reg = memory[PC++];
                    uint8_t address = memory[PC++];
                    memory[address] = registers[reg];
                    break;
                }
                case ADD: { // ADD reg1, reg2
                    uint8_t reg1 = memory[PC++];
                    uint8_t reg2 = memory[PC++];
                    registers[reg1] += registers[reg2];
                    break;
                }
                case SUB: { // SUB reg1, reg2
                    uint8_t reg1 = memory[PC++];
                    uint8_t reg2 = memory[PC++];
                    registers[reg1] -= registers[reg2];
                    break;
                }
                case JMP: { // JMP address
                    uint8_t address = memory[PC++];
                    PC = address;
                    break;
                }
                case IN: { // IN reg
                    uint8_t reg = memory[PC++];
                    registers[reg] = getBinaryInput();
                    break;
                }
                case OUT: { // OUT reg
                    uint8_t reg = memory[PC++];
                    cout << "Output (Binary): " << bitset<8>(registers[reg]) << endl;
                    break;
                }
                case HLT: // HALT execution
                    running = false;
                    break;
                default:
                    cout << "Unknown instruction at address " << (int)(PC - 1) << endl;
                    running = false;
                    break;
            }
        }
    }

    void printState() {
        cout << "Registers: ";
        for (int i = 0; i < NUM_REGISTERS; i++) {
            cout << "R" << i << "=" << (int)registers[i] << " ";
        }
        cout << endl;
    }
};

// Simple Assembler (Converts Assembly to Binary)
vector<uint8_t> simpleAssembler(vector<string> assemblyCode) {
    unordered_map<string, uint8_t> opcodes = {
        {"NOP", NOP}, {"LOAD", LOAD}, {"STORE", STORE}, {"ADD", ADD},
        {"SUB", SUB}, {"JMP", JMP}, {"IN", IN}, {"OUT", OUT}, {"HLT", HLT}
    };

    vector<uint8_t> machineCode;
    for (auto& line : assemblyCode) {
        stringstream ss(line);
        string instruction;
        ss >> instruction;

        if (opcodes.find(instruction) != opcodes.end()) {
            machineCode.push_back(opcodes[instruction]);

            if (instruction == "LOAD" || instruction == "STORE" || instruction == "IN" || instruction == "OUT") {
                int reg, val;
                ss >> reg;
                machineCode.push_back(reg);
                if (instruction != "IN" && instruction != "OUT") {
                    ss >> val;
                    machineCode.push_back(val);
                }
            } else if (instruction == "ADD" || instruction == "SUB") {
                int reg1, reg2;
                ss >> reg1 >> reg2;
                machineCode.push_back(reg1);
                machineCode.push_back(reg2);
            } else if (instruction == "JMP") {
                int addr;
                ss >> addr;
                machineCode.push_back(addr);
            }
        }
    }
    return machineCode;
}

// Main Function
int main() {
    VirtualCPU cpu;

    // Example Assembly Code with Input and Output
    vector<string> assemblyCode = {
        "IN 0",      // Take user input and store in R0
        "IN 1",      // Take another input in R1
        "ADD 0 1",   // R0 = R0 + R1
        "OUT 0",     // Print R0 in binary
        "STORE 0 20", // Store result in memory[20]
        "HLT"        // Halt
    };

    // Convert to Binary Machine Code
    vector<uint8_t> program = simpleAssembler(assemblyCode);

    // Load Program into CPU Memory
    cpu.loadProgram(program);

    // Execute Program
    cpu.execute();

    // Print CPU State
    cpu.printState();

    return 0;
}
