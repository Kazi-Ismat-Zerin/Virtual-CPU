
# Enable basic input/output operations.

## Implement simulated I/O devices (keyboard, display).
This program simulates basic input/output operations by using two custom classes: ``` Keyboard ``` and ``` Display ```. The ``` Keyboard ```  class allows reading a single character from the user (simulating key press), and the ``` Display ``` class allows displaying that character on the screen. The program prompts the user to press a key and then displays the pressed key as an output message.

# Classes and Their Methods:
1. Class: ``` Keyboard ```

- Purpose: Simulates reading input from a keyboard.
- Method: ``` readKey() ```
- Description: This method reads a single character from the user's input (keyboard) using ``` std::cin ```.
- Returns: A ``` char ``` that represents the key pressed by the user.

2. Class: ``` Display ```

- Purpose: Simulates displaying a message (character) on the screen.
- Method: ``` showMessage(char message) ```
- Description: This method prints the provided message (a character) to the console using ``` std::cout```.
- Parameters: ``` message``` (char) - The character to be displayed.

𝐌𝐚𝐢𝐧 𝐏𝐫𝐨𝐠𝐫𝐚𝐦 𝐅𝐥𝐨𝐰:

1.  𝐈𝐧𝐢𝐭𝐢𝐚𝐥𝐢𝐳𝐚𝐭𝐢𝐨𝐧:


Two objects are created: ``` keyboard``` (of type ``` Keyboard```) and ``` display``` (of type ``` Display```).

2. 𝐔𝐬𝐞𝐫 𝐈𝐧𝐩𝐮𝐭:
The program prompts the user with "Press any key: ".
The ``` keyboard.readKey()``` method is called to capture the character the user enters.

3. 𝐎𝐮𝐭𝐩𝐮𝐭:
The character entered by the user is passed to the ``` display.showMessage()``` method, which outputs it to the screen.

4. 𝐏𝐫𝐨𝐠𝐫𝐚𝐦 𝐂𝐨𝐦𝐩𝐥𝐞𝐭𝐢𝐨𝐧:

After the key is displayed, the program terminates.

## Create I/O instructions and integrate them with the CPU.
This C++ program simulates basic input/output operations with a simple CPU model. It takes an integer input from the user, processes it (by doubling the input), and then outputs the result.

𝐂𝐥𝐚𝐬𝐬: ```CPU```
- ```processInput(int input)```: Simulates CPU processing of input by printing it.
- ```sendOutput(int output)```: Simulates CPU sending output by printing the processed result.
𝐌𝐚𝐢𝐧 𝐅𝐥𝐨𝐰:
1. 𝐔𝐬𝐞𝐫 𝐈𝐧𝐩𝐮𝐭: Prompts the user to enter a number.
2. 𝐏𝐫𝐨𝐜𝐞𝐬𝐬𝐢𝐧𝐠: The CPU processes the input (doubles it).
3.  𝐎𝐮𝐭𝐩𝐮𝐭: The processed output is displayed.

## Test with I/O-intensive programs.
This C++ program simulates a simple system with input, processing, and output components, resembling the interaction between a CPU, keyboard, and display. Here's how it works:

1. 𝐈𝐧𝐩𝐮𝐭 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 (𝐤𝐞𝐲𝐛𝐨𝐚𝐫𝐝𝐈𝐧𝐩𝐮𝐭):
- Prompts the user to enter input from the keyboard.
- Reads the entire line using getline.
2. 𝐎𝐮𝐭𝐩𝐮𝐭 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧 (𝐝𝐢𝐬𝐩𝐥𝐚𝐲𝐎𝐮𝐭𝐩𝐮𝐭):
- Displays a processed string with a [Display] prefix.
3. 𝐂𝐏𝐔 𝐂𝐥𝐚𝐬𝐬:
- Encapsulates the logic for processing the input.
4. 𝐈𝐧 𝐭𝐡𝐞 𝐞𝐱𝐞𝐜𝐮𝐭𝐞 𝐦𝐞𝐭𝐡𝐨𝐝:
- Takes input from the keyboardInput function.
- Processes the input by converting it to uppercase.
- Outputs the result using the displayOutput function.
5. 𝐌𝐚𝐢𝐧 𝐅𝐮𝐧𝐜𝐭𝐢𝐨𝐧:
- Instantiates the CPU object and calls its execute method to run the workflow.

