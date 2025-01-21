#include <iostream>
#include <bitset>
#include <unordered_map>
using namespace std;

class Keyboard {
public:
    void input() {
        int input;
        cout << "Enter a number (binary input): ";
        cin >> input;
        binary_input = bitset<8>(input);  // Assume 8-bit input for simplicity
    }

    bitset<8> getInput() {
        return binary_input;
    }

private:
    bitset<8> binary_input;
};

class Display {
public:
    void output(const bitset<8>& data) {
        cout << "Binary output to display: " << data << endl;
    }
};

class CPU {
public:
    // Simulated memory and I/O registers
    uint8_t memory[65536];  // 64KB memory
    uint16_t IO_KEYBOARD = 0xFF00;  // Keyboard input address
    uint16_t IO_DISPLAY = 0xFF01;   // Display output address

    uint16_t PC = 0;  // Program counter
    uint8_t ACC = 0;  // Accumulator (simplified)

    void initialize() {
        memory[IO_KEYBOARD] = 0;  // Keyboard input initially 0
        memory[IO_DISPLAY] = 0;    // Display output initially 0
    }

    void execute() {
        while (PC < 65536) {
            uint8_t instruction = memory[PC];  // Fetch instruction
            PC++;

            switch (instruction) {
                case 0x01:  // READ from keyboard (example)
                    ACC = readKeyboard();
                    break;

                case 0x02:  // WRITE to display (example)
                    writeDisplay(ACC);
                    break;

                case 0xFF:  // Halt (example)
                    return;

                default:
                    cout << "Unknown instruction: " << hex << (int)instruction << endl;
                    return;
            }
        }
    }

    uint8_t readKeyboard() {
        // Simulate reading a key press
        cout << "Enter a key: ";
        char key;
        cin >> key;
        memory[IO_KEYBOARD] = (uint8_t)key;  // Store the key in I/O register
        return memory[IO_KEYBOARD];  // Return the key's value
    }

    void writeDisplay(uint8_t value) {
        // Simulate writing to the display (printing as ASCII)
        cout << "Display: " << (char)value << endl;
        memory[IO_DISPLAY] = value;  // Store in display register
    }
};

int main() {
    CPU cpu;
    cpu.initialize();

    // Simulating a program in assembly-like format:
    // 0x01 -> READ from keyboard
    // 0x02 -> WRITE to display
    // 0xFF -> HALT

    cpu.memory[0] = 0x01;  // Read keyboard
    cpu.memory[1] = 0x02;  // Write to display
    cpu.memory[2] = 0xFF;  // Halt

    cpu.execute();

    return 0;
}
