#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;
enum Opcode {
    ADD = 0x1,
    SUB = 0x2,
    LOAD = 0x3,
    STORE = 0x4
};

unordered_map<string, int> registers = {
    {"R0", 0x0},
    {"R1", 0x1},
    {"R2", 0x2},
    {"R3", 0x3}
};

uint16_t assemble(const string& instruction) {
    istringstream ss(instruction);
    string op, dst, src1, src2;
    ss >> op >> dst >> src1 >> src2;

    uint16_t machineCode = 0;

    if (op == "ADD") {
        machineCode |= (ADD << 12);
    } else if (op == "SUB") {
        machineCode |= (SUB << 12);
    } else if (op == "LOAD") {
        machineCode |= (LOAD << 12);
    } else if (op == "STORE") {
        machineCode |= (STORE << 12);
    }

    machineCode |= (registers[dst] << 8);


    if (src1 != "") machineCode |= (registers[src1] << 4);
    if (src2 != "") machineCode |= registers[src2];

    return machineCode;
}

int main() {
    vector<string> instructions = {
        "ADD R1 R2 R3",
        "SUB R1 R2 R3",
        "LOAD R1 0x10",
        "STORE R1 0x10"
    };

    cout << "Machine Code:" << endl;
    for (const auto& instr : instructions) {
        uint16_t machineCode = assemble(instr);
        cout << instr << " -> 0x" << hex << machineCode << endl;
    }

    return 0;
}
