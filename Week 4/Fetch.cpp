#include <iostream>
#include <vector>
using namespace std;

class CPU {
public:
    vector<int> memory;
    int PC;
    CPU(vector<int> program) : memory(program), PC(0) {}
    int fetch() {
        if (PC < memory.size()) {
            int instruction = memory[PC];
            PC++;
            return instruction;
        } else {
            cout << "Program Counter out of bounds!" <<endl;
            return -1;
        }
    }
    void execute() {
        int instruction;
        while ((instruction = fetch()) != -1) {
            cout << "Fetched Instruction: " << instruction << endl;
        }
    }
};
int main() {
    vector<int> program = { 100, 200, 300, 400, 500 };
    CPU cpu(program);
    cpu.execute();

    return 0;
}
