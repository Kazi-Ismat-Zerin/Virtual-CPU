
#include <iostream>
#include <string>
using namespace std;

class ALU {
public:

    int execute(int operand_a, int operand_b, const string& opcode) {

        if (opcode == "ADD") {
            return operand_a + operand_b;
        } else if (opcode == "SUB") {
            return operand_a - operand_b;
        } else if (opcode == "AND") {
            return operand_a & operand_b;
        } else if (opcode == "OR") {
            return operand_a | operand_b;
        } else if (opcode == "XOR") {
            return operand_a ^ operand_b;
        } else if (opcode == "EQ") {
            return (operand_a == operand_b) ? 1 : 0;
        } else if (opcode == "GT") {
            return (operand_a > operand_b) ? 1 : 0;
        } else if (opcode == "LT") {
            return (operand_a < operand_b) ? 1 : 0;
        } else {
            cerr << "Invalid operation!" <<endl;
            return 0;
        }
    }
};

int main() {
    ALU alu;

    int operand_a = 10;
    int operand_b = 5;


    cout << "ADD: " << alu.execute(operand_a, operand_b, "ADD") <<endl;
    cout << "SUB: " << alu.execute(operand_a, operand_b, "SUB") <<endl;
    cout << "AND: " << alu.execute(operand_a, operand_b, "AND") <<endl;
    cout << "OR: " << alu.execute(operand_a, operand_b, "OR") <<endl;
    cout << "XOR: " << alu.execute(operand_a, operand_b, "XOR") <<endl;
    cout << "EQ: " << alu.execute(operand_a, operand_b, "EQ") <<endl;
    cout << "GT: " << alu.execute(operand_a, operand_b, "GT") <<endl;
    cout << "LT: " << alu.execute(operand_a, operand_b, "LT") <<endl;

    return 0;
}
