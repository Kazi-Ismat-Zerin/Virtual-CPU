
# Add advanced CPU features.

1. Implement branching and control flow instructions.
- 𝐁𝐫𝐚𝐧𝐜𝐡𝐢𝐧𝐠: We will implement jump instructions like ``` JMP ``` (unconditional jump) and conditional jumps like ``` JEQ ``` (jump if equal) and ``` JNE ``` (jump if not equal).
 
- 𝐂𝐨𝐧𝐭𝐫𝐨𝐥 𝐅𝐥𝐨𝐰: These instructions control the flow of execution within the CPU, allowing us to make decisions and loop over instructions.
2. Add Support for Subroutines and Interrupts
 
- 𝐒𝐮𝐛𝐫𝐨𝐮𝐭𝐢𝐧𝐞𝐬: We will implement ``` CALL ``` and ``` RET ``` instructions to simulate subroutine calls and returns.

- 𝐈𝐧𝐭𝐞𝐫𝐫𝐮𝐩𝐭𝐬: A basic interrupt mechanism will be implemented, allowing the CPU to handle specific events asynchronously (e.g., user input).
3. Integrate a Simple Pipeline Mechanism
 
- 𝐏𝐢𝐩𝐞𝐥𝐢𝐧𝐞: A simple pipeline will allow the CPU to fetch, decode, and execute instructions in parallel, improving efficiency. We will simulate a 3-stage pipeline with stages for instruction fetch, decode, and execute.

# Explanation of Key Features
1. 𝐁𝐫𝐚𝐧𝐜𝐡𝐢𝐧𝐠 𝐚𝐧𝐝 𝐂𝐨𝐧𝐭𝐫𝐨𝐥 𝐅𝐥𝐨𝐰:

- 𝐉𝐌𝐏 (𝐔𝐧𝐜𝐨𝐧𝐝𝐢𝐭𝐢𝐨𝐧𝐚𝐥 𝐉𝐮𝐦𝐩): The program jumps to a new address in memory.
- 𝐉𝐄𝐐 (𝐉𝐮𝐦𝐩 𝐢𝐟 𝐄𝐪𝐮𝐚𝐥): The program checks the condition and jumps if the register value is equal to zero.
- 𝐂𝐀𝐋𝐋 𝐚𝐧𝐝 𝐑𝐄𝐓 (𝐒𝐮𝐛𝐫𝐨𝐮𝐭𝐢𝐧𝐞 𝐂𝐚𝐥𝐥 𝐚𝐧𝐝 𝐑𝐞𝐭𝐮𝐫𝐧): The program can call a subroutine, store the return address on a stack, and then return after execution.
- 𝐈𝐧𝐭𝐞𝐫𝐫𝐮𝐩𝐭𝐬: Simulated by setting an ```  interrupt_flag ```, causing the program to stop execution and handle an interrupt.
2. 𝐏𝐢𝐩𝐞𝐥𝐢𝐧𝐞 𝐌𝐞𝐜𝐡𝐚𝐧𝐢𝐬𝐦:

- 𝐅𝐞𝐭𝐜𝐡: Fetch the current instruction from memory.
- 𝐃𝐞𝐜𝐨𝐝𝐞 𝐚𝐧𝐝 𝐄𝐱𝐞𝐜𝐮𝐭𝐞: Decode and execute the instruction based on its type.
We simulate a pipeline, though it's a simplified version that processes each instruction sequentially in this program.

3. 𝐏𝐫𝐨𝐠𝐫𝐚𝐦 𝐅𝐥𝐨𝐰:

- The program reads instructions from memory, fetches them, decodes them, and performs the corresponding actions (e.g., jumping to a different memory address or processing interrupts).




