#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
// Define simple instructions
struct Instruction {
    string opcode;
    int operand1;
    int operand2;
};
// A simple ALU function
int ALU(const string& opcode, int operand1, int operand2) {
    if (opcode == "ADD") return operand1 + operand2;
    if (opcode == "SUB") return operand1 - operand2;
    if (opcode == "MUL") return operand1 * operand2;
    if (opcode == "DIV" && operand2 != 0) return operand1 / operand2;
    cout << "Invalid operation or division by zero!" << endl;
    return 0;
}
int main() {
    unordered_map<string, int> registers = {{"R1", 0}, {"R2", 0}, {"R3", 0}};
    vector<Instruction> program = {
        {"ADD", 5, 3},  // R1 = 5 + 3
        {"SUB", 10, 2}, // R2 = 10 - 2
        {"MUL", 4, 3},  // R3 = 4 * 3
    };
    // Simulate the Fetch-Decode-Execute cycle
    for (size_t pc = 0; pc < program.size(); ++pc) {
        // Fetch
        Instruction instr = program[pc];

        // Decode & Execute
        int result = ALU(instr.opcode, instr.operand1, instr.operand2);
        string regName = "R" + to_string(pc + 1);
        if (registers.find(regName) != registers.end()) {
            registers[regName] = result;
            cout << regName << " = " << result << endl;
        }
    }
    return 0;
}


