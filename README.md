# Project Name: Virtual CPU

A virtual CPU (vCPU) is an abstraction that represents a portion of a physical CPU, typically used in virtualized environments like virtual machines (VMs) or containers. In a virtualized system, a single physical CPU can be divided into multiple virtual CPUs, enabling several operating systems and applications to run concurrently on the same hardware.

# Code Breakdown

The project consists of multiple classes representing CPU components:

## 1. 𝐀𝐋𝐔 (𝐀𝐫𝐢𝐭𝐡𝐦𝐞𝐭𝐢𝐜 𝐋𝐨𝐠𝐢𝐜 𝐔𝐧𝐢𝐭)
Handles arithmetic and logical operations.

- 𝐌𝐞𝐭𝐡𝐨𝐝:

```
 int ALU(int op, int a, int b) {
    switch (op) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        case 3: return a / (b ? b : 1);
        default: return 0;
    }
}
```
- 𝐎𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧: ADD, SUB, MUL, DIV.

- 𝐑𝐞𝐭𝐮𝐫𝐧: 8-bit binary string of the result.

## 2. Registers
Stores temporary values during computation.

- 𝐌𝐞𝐭𝐡𝐨𝐝:

```
struct Registers {
    int R[4] = {0}; // 4 General Purpose Registers
    int PC = 0;  // Program Counter
    int IR = 0;  // Instruction Register
};
```
- 𝐎𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧: Registers, Program Counter(PC), Instruction Register(IR).

- Values stored as 8-bit binary.

## 3. Memory
Stores instructions and data.

- 𝐌𝐞𝐭𝐡𝐨𝐝:

```
vector<int> memory(256, 0);
```
- Supports a memory system with 256 addressable locations and a register file with 8-bit registers (R).

## 4. Instruction Execution Flow

- 𝐅𝐞𝐭𝐜𝐡: Retrieve instruction from user input.

- 𝐃𝐞𝐜𝐨𝐝𝐞: Break down the instruction into operation and operands.

- 𝐄𝐱𝐞𝐜𝐮𝐭𝐞: Process the operation using ALU, Registers, Control Unit, and Memory.

## 5. Instruction Set

- 𝐌𝐞𝐭𝐡𝐨𝐝:
```
enum Instructions { ADD, SUB, MUL, DIV, LOAD, STORE, JMP, PRINT, HALT, IN, OUT };
```
- 𝐀𝐃𝐃, 𝐒𝐔𝐁, 𝐌𝐔𝐋, 𝐃𝐈𝐕 → Arithmetic operations.
- 𝐋𝐎𝐀𝐃, 𝐒𝐓𝐎𝐑𝐄 → Memory operations.
- 𝐉𝐌𝐏  → Jump to another instruction.
- 𝐏𝐑𝐈𝐍𝐓 → Print a value.
-  𝐇𝐀𝐋𝐓 → Stop execution.
- 𝐈𝐍, 𝐎𝐔𝐓 → Handle input and output.


## 6. Assembler

- Converts 𝐚𝐬𝐬𝐞𝐦𝐛𝐥𝐲 𝐢𝐧𝐬𝐭𝐫𝐮𝐜𝐭𝐢𝐨𝐧𝐬 (text format) into 𝐦𝐚𝐜𝐡𝐢𝐧𝐞 𝐜𝐨𝐝𝐞 (integer representation).

- Uses an 𝐨𝐩𝐜𝐨𝐝𝐞 𝐦𝐚𝐩𝐩𝐢𝐧𝐠 (unordered_map) for translation.

𝐄𝐱𝐚𝐦𝐩𝐥𝐞: Assembly → "𝐀𝐃𝐃" → Machine code → 𝟎 (opcode for ADD).

## 7. I/O Devices

Handles input and output operations.

- 𝐌𝐞𝐭𝐡𝐨𝐝:
```
queue<int> inputBuffer;
vector<int> outputBuffer;

void inputDevice(int value) {
    inputBuffer.push(value);
}

int outputDevice() {
    if (!outputBuffer.empty()) {
        int value = outputBuffer.back();
        outputBuffer.pop_back();
        return value;
    }
    return -1; // No output available
}
```
- 𝐈𝐧𝐩𝐮𝐭𝐁𝐮𝐟𝐟𝐞𝐫: Stores incoming values forinput operations.
 - 𝐎𝐮𝐭𝐩𝐮𝐭𝐁𝐮𝐟𝐟𝐞𝐫: Stores output values for output operations.
- 𝐈𝐧𝐩𝐮𝐭𝐃𝐞𝐯𝐢𝐜𝐞(𝐢𝐧𝐭 𝐯𝐚𝐥𝐮𝐞): Adds an integer value to inputBuffer.
- 𝐎𝐮𝐭𝐩𝐮𝐭𝐃𝐞𝐯𝐢𝐜𝐞(): Retrieves the last value from outputBuffer (returns -1 if empty).

## Example Execution
𝐈𝐧𝐩𝐮𝐭: 10

𝐈𝐧𝐬𝐭𝐫𝐮𝐜𝐭𝐢𝐨𝐧𝐬 𝐄𝐱𝐞𝐜𝐮𝐭𝐢𝐨𝐧 𝐅𝐥𝐨𝐰:

-  𝐈𝐍 → Reads 10 into R[1].
 - 𝐀𝐃𝐃 → Adds R[1] and R[2] (both are 10 and 0), stores in R[0].
- 𝐎𝐔𝐓 → Pushes 10 to outputBuffer.
- 𝐇𝐀𝐋𝐓 → Stops execution.

 𝐎𝐮𝐭𝐩𝐮𝐭 𝐢𝐬 𝐩𝐫𝐢𝐧𝐭𝐞𝐝 𝐢𝐧 𝐛𝐢𝐧𝐚𝐫𝐲:  𝟎𝟎𝟎𝟎𝟏𝟎𝟏𝟎






