#include <iostream>
using namespace std;

class CPU {
private:
    int pc;
    int register_value;

public:
    CPU() : pc(0), register_value(0) {}
    void setRegisterValue(int value) {
        register_value = value;
    }
    void run() {
        while (pc < 10) {
            if (pc == 0) {
                cout << "At instruction 0: JMP to 4" << endl;
                pc = 4;
            }
            else if (pc == 4) {
                cout << "At instruction 4: JEQ (check if register_value == 0)" << endl;
                if (register_value == 0) {
                    cout << "Register is 0, jumping to instruction 7" << endl;
                    pc = 7;
                } else {
                    cout << "Register is non-zero, moving to next instruction" << endl;
                    pc = 5;
                }
            }
            else if (pc == 5) {
                cout << "At instruction 5: JNE (check if register_value != 0)" << endl;
                if (register_value != 0) {
                    cout << "Register is non-zero, jumping to instruction 9" << endl;
                    pc = 9;
                } else {
                    cout << "Register is 0, moving to next instruction" << endl;
                    pc = 6;
                }
            }
            else if (pc == 6) {
                cout << "At instruction 6: End of program" << endl;
                break;
            }
            else if (pc == 7) {
                cout << "At instruction 7: End of program (JEQ case)" << endl;
                break;
            }
            else if (pc == 9) {
                cout << "At instruction 9: End of program (JNE case)" << endl;
                break;
            }
        }
    }
};

int main() {
    CPU cpu;
    cpu.setRegisterValue(0);
    cpu.run();
    return 0;
}
