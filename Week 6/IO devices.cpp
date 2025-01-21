#include <iostream>
#include <bitset>
using namespace std;

class Keyboard {
public:
    void input() {
        int input;
        cout << "Enter a number (binary input): ";
        cin >> input;
        binary_input = bitset<8>(input); // Assume 8-bit input for simplicity
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

int main() {
    Keyboard keyboard;
    Display display;

    keyboard.input();
    bitset<8> input_data = keyboard.getInput();

    display.output(input_data);

    return 0;
}
