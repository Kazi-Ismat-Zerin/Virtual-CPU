
# ALU


The Arithmetic Logic Unit (ALU) is a critical component of a CPU. It performs arithmetic operations (like addition and subtraction) and logic operations (like AND, OR, XOR).

# ALU Features
The ALU should be able to:

1. 𝐏𝐞𝐫𝐟𝐨𝐫𝐦 𝐚𝐫𝐢𝐭𝐡𝐦𝐞𝐭𝐢𝐜 𝐨𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧𝐬 : like addition and subtraction.
2. 𝐏𝐞𝐫𝐟𝐨𝐫𝐦 𝐥𝐨𝐠𝐢𝐜𝐚𝐥 𝐨𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧𝐬 : like AND, OR, XOR.
3. 𝐒𝐮𝐩𝐩𝐨𝐫𝐭 𝐜𝐨𝐦𝐩𝐚𝐫𝐢𝐬𝐨𝐧 𝐨𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧𝐬 : like equality check (==), greater-than (>), and less-than (<).




## Included Libraries

1.  𝐈𝐧𝐜𝐥𝐮𝐝𝐞𝐬 𝐚𝐧𝐝 𝐍𝐚𝐦𝐞𝐬𝐩𝐚𝐜𝐞:

```bash
  #include <iostream>
  #include <string>
  using namespace std;

```
2. 𝐀𝐋𝐔 𝐂𝐥𝐚𝐬𝐬 𝐃𝐞𝐟𝐢𝐧𝐢𝐭𝐢𝐨𝐧:










- 𝐜𝐥𝐚𝐬𝐬 𝐀𝐋𝐔: Defines a class called ALU that represents the Arithmetic Logic Unit.


- 𝐩𝐮𝐛𝐥𝐢𝐜: This section makes the methods and members of the class accessible from outside the class.


3. 𝐏𝐮𝐛𝐥𝐢𝐜 𝐌𝐞𝐭𝐡𝐨𝐝: 𝐞𝐱𝐞𝐜𝐮𝐭𝐞:
```bash
int execute(int operand_a, int operand_b, const string& opcode)
```
- This is the method inside the 𝐀𝐋𝐔 class that performs the operations. It takes three parameters:
- 𝐨𝐩𝐞𝐫𝐚𝐧𝐝_𝐚 and 𝐨𝐩𝐞𝐫𝐚𝐧𝐝_𝐛: The two integers on which the operation will be performed.
- 𝐨𝐩𝐜𝐨𝐝𝐞: A string that specifies which operation to perform (e.g., "ADD", "SUB", etc.).

4. 𝐎𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧𝐬:
- The function checks the value of opcode and performs the corresponding operation:
- 𝐀𝐃𝐃: Adds the two operands (operand_a + operand_b).
- 𝐒𝐔𝐁: Subtracts the second operand from the first (operand_a - operand_b).
- 𝐀𝐍𝐃: Performs bitwise AND (operand_a & operand_b).
- 𝐎𝐑: Performs bitwise OR (operand_a | operand_b).
- 𝐗𝐎𝐑: Performs bitwise XOR (operand_a ^ operand_b).
- 𝐄𝐐: Checks if the two operands are equal (operand_a == operand_b). If they are equal, returns 1; otherwise, returns 0.
- 𝐆𝐓: Checks if the first operand is greater than the second (operand_a > operand_b). If true, returns 1; otherwise, returns 0.
- 𝐋𝐓: Checks if the first operand is less than the second (operand_a < operand_b). If true, returns 1; otherwise, returns 0.
- If none of these operations match the given opcode, an error message is printed using cerr, and 0 is returned.

5. 𝐌𝐚𝐢𝐧 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧:
```bash
int main() {
    ALU alu;  // Create an instance of the ALU class.

    int operand_a = 10;  // Define the first operand.
    int operand_b = 5;   // Define the second operand.

    // Perform various operations using the ALU object and print results:
    cout << "ADD: " << alu.execute(operand_a, operand_b, "ADD") << endl;
    cout << "SUB: " << alu.execute(operand_a, operand_b, "SUB") << endl;
    cout << "AND: " << alu.execute(operand_a, operand_b, "AND") << endl;
    cout << "OR: " << alu.execute(operand_a, operand_b, "OR") << endl;
    cout << "XOR: " << alu.execute(operand_a, operand_b, "XOR") << endl;
    cout << "EQ: " << alu.execute(operand_a, operand_b, "EQ") << endl;
    cout << "GT: " << alu.execute(operand_a, operand_b, "GT") << endl;
    cout << "LT: " << alu.execute(operand_a, operand_b, "LT") << endl;

    return 0;
}
```
- ALU alu;: Creates an object of the ALU class, which allows you to use its execute method to perform operations.

- operand_a = 10, operand_b = 5;: Defines two integer operands, operand_a and operand_b.

- 𝐎𝐩𝐞𝐫𝐚𝐭𝐢𝐨𝐧𝐬:

- The program then performs the following operations using the alu.execute() method:
- 𝐀𝐃𝐃: Adds operand_a and operand_b (10 + 5 = 15).
- 𝐒𝐔𝐁: Subtracts operand_b from operand_a (10 - 5 = 5).
- 𝐀𝐍𝐃: Performs bitwise AND on operand_a and operand_b (10 & 5 = 0).
- 𝐎𝐑: Performs bitwise OR on operand_a and operand_b (10 | 5 = 15).
- 𝐗𝐎𝐑: Performs bitwise XOR on operand_a and operand_b (10 ^ 5 = 15).
- 𝐄𝐐: Checks if operand_a is equal to operand_b (10 == 5 is false, so result is 0).
- 𝐆𝐓: Checks if operand_a is greater than operand_b (10 > 5 is true, so result is 1).
- 𝐋𝐓:  Checks if operand_a is less than operand_b (10 < 5 is false, so result is 0).
- Each result is printed using cout, followed by a newline (endl).



