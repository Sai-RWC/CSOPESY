#include "KeyboardHandler.h"
#include <conio.h>
#include <iostream>

void KeyboardEventHandler::OnKeyDown(char key)
{
    std::cout << "Key Down: " << key << std::endl;
}

void KeyboardEventHandler::OnKeyUp(char key)
{
    std::cout << "Key Up: " << key << std::endl;
}
    
void PollKeyboard(IKeyboardEvent& keyboardEvent)
{
    while (true) {
        if (_kbhit()) {
            char key = _getch();

            if (GetAsyncKeyState(key) & 0x8000) {
                keyboardEvent.OnKeyDown(key);
                std::cout << "Key Down: " << key << std::endl;
            } else {
                keyboardEvent.OnKeyUp(key);
                std::cout << "Key Up: " << key << std::endl;
            }
        }
        
    }
}
