#include <iostream>
using namespace std;
class ALU {
public:
    int execute(int operand_a, int operand_b, string operation) {
        if (operation == "ADD") {
            return operand_a + operand_b;
        } else if (operation == "SUB") {
            return operand_a - operand_b;
        } else {
            cout << "Invalid Operation!" << endl;
            return 0;
        }
    }
};

class GeneralPurposeRegisters {
private:
    int registers[8];
public:
    GeneralPurposeRegisters() {
        for (int i = 0; i < 8; i++) {
            registers[i] = 0;
        }
    }
    void write(int regIndex, int value) {
        if (regIndex >= 0 && regIndex < 8) {
            registers[regIndex] = value;
        } else {
            cout << "Invalid register index!" << endl;
        }
    }
    int read(int regIndex) {
        if (regIndex >= 0 && regIndex < 8) {
            return registers[regIndex];
        } else {
            cout << "Invalid register index!" << endl;
            return 0;
        }
    }
};

int main() {
    ALU alu;
    GeneralPurposeRegisters gpr;
    gpr.write(0, 10);  // R0 = 10
    gpr.write(1, 5);   // R1 = 5

    int value1 = gpr.read(0);  // Read R0
    int value2 = gpr.read(1);  // Read R1

    int result_add = alu.execute(value1, value2, "ADD");
    cout << "R0 + R1 = " << result_add << endl;

    int result_sub = alu.execute(value1, value2, "SUB");
    cout << "R0 - R1 = " << result_sub << endl;

    return 0;
}
