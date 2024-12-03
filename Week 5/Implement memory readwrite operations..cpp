#include <iostream>
using namespace std;

class VirtualMemory {
public:
    static const int MEMORY_SIZE = 1024;
    int memory[MEMORY_SIZE];
    VirtualMemory() {
        for (int i = 0; i < MEMORY_SIZE; i++) {
            memory[i] = 0;
        }
    }
    // Read from memory at a specific address
    int read(int address) {
        if (address < 0 || address >= MEMORY_SIZE) {
            cout << "Error: Address out of range!" << endl;
            return -1;
        }
        return memory[address];
    }
    // Write to memory at a specific address
    void write(int address, int value) {
        if (address < 0 || address >= MEMORY_SIZE) {
            cout << "Error: Address out of range!" << endl;
            return;
        }
        memory[address] = value;
    }
};
int main() {
    VirtualMemory vm;

    vm.write(10, 42);  // Write value 42 at address 10
    vm.write(500, 99); // Write value 99 at address 500

    cout << "Value at address 10: " << vm.read(10) << endl;
    cout << "Value at address 500: " << vm.read(500) << endl;
    cout << "Value at address 1500: " << vm.read(1500) << endl;
    return 0;
}
