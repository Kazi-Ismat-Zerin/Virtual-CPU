#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

const int MEMORY_SIZE = 1024;
class MemoryManager {
private:
    vector<uint8_t> memory;

public:
    MemoryManager() : memory(MEMORY_SIZE, 0) {}
    uint8_t read(int address) {
        if (address < 0 || address >= MEMORY_SIZE) {
            throw out_of_range("Invalid memory address");
        }
        return memory[address];
    }
    void write(int address, uint8_t value) {
        if (address < 0 || address >= MEMORY_SIZE) {
            throw out_of_range("Invalid memory address");
        }
        memory[address] = value;
    }
    void displayMemory() {
        for (int i = 0; i < MEMORY_SIZE; ++i) {
            if (i % 16 == 0) cout << "\n";
            cout << static_cast<int>(memory[i]) << " ";
        }
        cout << "\n";
    }
};

int main() {
    MemoryManager memManager;

    memManager.write(0, 42);
    memManager.write(1, 255);

    cout << "Value at address 0: " << static_cast<int>(memManager.read(0)) << "\n";
    cout << "Value at address 1: " << static_cast<int>(memManager.read(1)) << "\n";
    memManager.displayMemory();

    return 0;
}
