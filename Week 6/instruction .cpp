
#include <iostream>
#include <unordered_map>
using namespace std;

class CPU {
public:
    // Simulated memory
    uint8_t memory[65536];  // 64KB memory

    // I/O registers (example)
    uint16_t IO_KEYBOARD = 0xFF00;   // Keyboard input address
    uint16_t IO_DISPLAY = 0xFF01;    // Display output address

    // State of the CPU
    uint16_t PC = 0;  // Program counter
    uint8_t ACC = 0;  // Accumulator (simplified example)

    void initialize() {
        // Initialize memory with I/O registers
        memory[IO_KEYBOARD] = 0;  // Keyboard input is initially 0
        memory[IO_DISPLAY] = 0;    // Display output is initially 0
    }

    void execute() {
        // Example program execution loop
        while (PC < 65536) {
            uint8_t instruction = memory[PC];  // Fetch instruction
            PC++;

            switch (instruction) {
                case 0x01:  // READ from keyboard (example instruction)
                    ACC = readKeyboard();
                    break;

                case 0x02:  // WRITE to display (example instruction)
                    writeDisplay(ACC);
                    break;

                case 0xFF:  // Halt (example)
                    return;

                default:
                    cout << "Unknown instruction: " << hex << (int)instruction <<endl;
                    return;
            }
        }
    }

    uint8_t readKeyboard() {
        // Simulate reading a key press
        cout << "Enter a key: ";
        char key;
        cin >> key;
        memory[IO_KEYBOARD] = (uint8_t)key;  // Store the key in the I/O register
        return memory[IO_KEYBOARD];  // Return the key's value
    }

    void writeDisplay(uint8_t value) {
        // Simulate writing to the display (printing the value as ASCII)
        cout << "Display: " << (char)value << endl;
        memory[IO_DISPLAY] = value;  // Store the value in the display register
    }
};

int main() {
    CPU cpu;
    cpu.initialize();

    // Example program: Read a key and display it
    cpu.memory[0] = 0x01;  // Read keyboard
    cpu.memory[1] = 0x02;  // Write to display
    cpu.memory[2] = 0xFF;  // Halt

    cpu.execute();

    return 0;
}
