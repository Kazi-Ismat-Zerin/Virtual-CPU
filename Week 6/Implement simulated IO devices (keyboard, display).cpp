#include <iostream>
#include <string>


class Keyboard {
public:

    char readKey() {
        char key;
        std::cin >> key;
        return key;
    }
};


class Display {
public:

    void showMessage(char message) {
        std::cout << message << std::endl;
    }
};

int main() {

    Keyboard keyboard;
    Display display;

    std::cout << "Press any key: ";

    char key = keyboard.readKey();


    display.showMessage(key);

    return 0;
}
