#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int registers[4] = {0};
// ALU Operations
int ALU(const string& operation, int operand1, int operand2) {
    if (operation == "ADD") return operand1 + operand2;
    if (operation == "SUB") return operand1 - operand2;
    if (operation == "MUL") return operand1 * operand2;
    if (operation == "DIV" && operand2 != 0) return operand1 / operand2;
    return 0;
}
// Fetch-Decode-Execute Cycle
void executeInstruction(const string& instruction) {
    string operation;
    int reg1, reg2, reg3;
    sscanf(instruction.c_str(), "%s R%d R%d R%d", &operation[0], &reg1, &reg2, &reg3);
    registers[reg1] = ALU(operation, registers[reg2], registers[reg3]);

    cout << "Registers: ";
    for (int reg : registers) cout << reg << " ";
    cout << "\n";
}
int main() {
    vector<string> program = {
        "ADD R0 R1 R2", // R0 = R1 + R2
        "MUL R1 R0 R3", // R1 = R0 * R3
        "SUB R2 R1 R0", // R2 = R1 - R0
    };
    registers[1] = 5;
    registers[2] = 3;
    registers[3] = 2;
    for (const string& instr : program) {
        cout << "Executing: " << instr << "\n";
        executeInstruction(instr);
    }
   return 0;
}
