#include <iostream>
using namespace std;

class VirtualMemory {
public:
    static const int CODE_SIZE = 100;
    static const int DATA_SIZE = 200;
    static const int STACK_SIZE = 100;
    static const int MEMORY_SIZE = CODE_SIZE + DATA_SIZE + STACK_SIZE;

    int memory[MEMORY_SIZE];
    int code_base = 0;
    int data_base = CODE_SIZE;
    int stack_base = CODE_SIZE + DATA_SIZE;
    VirtualMemory() {
        for (int i = 0; i < MEMORY_SIZE; i++) {
            memory[i] = 0;
        }
    }
    int read(int address) {
        if (address < 0 || address >= MEMORY_SIZE) {
            cout << "Error: Address out of range!" << endl;
            return -1;
        }
        return memory[address];
    }
    void write(int address, int value) {
        if (address < 0 || address >= MEMORY_SIZE) {
            cout << "Error: Address out of range!" << endl;
            return;
        }
        memory[address] = value;
    }
    int mapAddress(int segment, int offset) {
        int base_address;
        if (segment == 0) {
            base_address = code_base;
        } else if (segment == 1) {
            base_address = data_base;
        } else if (segment == 2) {
            base_address = stack_base;
        } else {
            cout << "Invalid segment!" << endl;
            return -1;
        }
        return base_address + offset;
    }
};
int main() {
    VirtualMemory vm;
    vm.write(vm.mapAddress(0, 10), 42);
    vm.write(vm.mapAddress(1, 50), 99);
    vm.write(vm.mapAddress(2, 20), 77);
    cout << "Code segment value at offset 10: " << vm.read(vm.mapAddress(0, 10)) << endl;
    cout << "Data segment value at offset 50: " << vm.read(vm.mapAddress(1, 50)) << endl;
    cout << "Stack segment value at offset 20: " << vm.read(vm.mapAddress(2, 20)) << endl;
    return 0;
}
