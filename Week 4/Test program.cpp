#include <iostream>
using namespace std;

class CPU {
public:
    int registers[4];
    int memory[10];
    int PC;
    CPU() {
        for (int i = 0; i < 4; i++) registers[i] = 0;
        for (int i = 0; i < 10; i++) memory[i] = 0;
        PC = 0;
    }
    void fetch() {
        PC++;
    }
    void execute() {
        switch (memory[PC - 1]) {
            case 1:
                registers[0] = memory[PC];
                break;
            case 2:
                registers[0] = registers[1] + registers[2];
                break;
            case 3:
                memory[PC] = registers[0];
                break;
            default:
                break;
        }
    }
    void run() {
        while (PC < 10) {
            fetch();
            execute();
        }
    }
    void printState() {
        cout << "Registers: ";
        for (int i = 0; i < 4; i++) {
            cout << "R" << i << ":" << registers[i] << " ";
        }
        cout << endl;
        cout << "Memory: ";
        for (int i = 0; i < 10; i++) {
            cout << "M" << i << ":" << memory[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    CPU cpu;
    cpu.memory[0] = 1;
    cpu.memory[1] = 5;
    cpu.memory[2] = 2;
    cpu.memory[3] = 0;
    cpu.memory[4] = 3;
    cpu.memory[5] = 0;

    cpu.run();
    cpu.printState();
   return 0;
}
