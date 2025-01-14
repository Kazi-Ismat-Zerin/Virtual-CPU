#include <iostream>
using namespace std;

class CPU {
private:
    int pc;

public:
    CPU() : pc(0) {}


    void run() {
        while (pc < 3) {
            cout << "Fetching instruction " << pc << endl;
            execute(pc);
            pc++;
        }
    }


    void execute(int instruction) {
        if (instruction == 0) {
            cout << "Executing Subroutine!" << endl;
        } else if (instruction == 1) {
            cout << "Executing Interrupt!" << endl;
        } else {
            cout << "Executing Instruction " << instruction << endl;
        }
    }
};

int main() {
    CPU cpu;


    cpu.run();

    return 0;
}
