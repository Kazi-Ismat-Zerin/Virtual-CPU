
# Key Components:

1. 𝐏𝐫𝐨𝐠𝐫𝐚𝐦 𝐂𝐨𝐮𝐧𝐭𝐞𝐫 (𝐏𝐂):

- The pc variable keeps track of the address of the next instruction in memory.
- After each instruction is executed, pc is incremented to point to the next instruction, unless changed by a jump instruction.

2. 𝐈𝐧𝐬𝐭𝐫𝐮𝐜𝐭𝐢𝐨𝐧 𝐑𝐞𝐠𝐢𝐬𝐭𝐞𝐫 (𝐈𝐑):

- The ir variable stores the instruction fetched from memory and is used to decide which operation to perform.

3. 𝐌𝐞𝐦𝐨𝐫𝐲:

- A simple array memory[5] holds the instructions: "LOAD", "ADD", "SUB", "JUMP", and "HALT". These are the instructions the CPU will execute.

# How It Works:
- 𝐅𝐞𝐭𝐜𝐡: The CPU fetches the instruction at the current value of pc (Program Counter) and stores it in ir (Instruction Register).
- 𝐄𝐱𝐞𝐜𝐮𝐭𝐞: The CPU executes the instruction stored in ir. If it's a "JUMP", it modifies pc to jump to instruction 3. After each instruction, pc is incremented to fetch the next instruction.
- 𝐑𝐮𝐧: The run() method repeatedly fetches and executes instructions until all instructions are processed.

