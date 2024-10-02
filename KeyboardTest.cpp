#include <iostream>
#include <windows.h>
#include <conio.h>


class IKeyboardEvent {
    public:
        virtual void OnKeyDown(char key) = 0;
        virtual void OnKeyUp(char key) = 0;

};

class KeyboardEventHandler : public IKeyboardEvent 
{
    public:
        void OnKeyDown(char key) override {
            std::cout << "Key Down: " << key << std::endl;
        }

        void OnKeyUp(char key) override {
            std::cout << "Key Up: " << key << std::endl;
        }
};

void PollKeyboard(IKeyboardEvent &keyboardEvent)
{
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            
            if (GetAsyncKeyState(key) & 0x8000) {
                keyboardEvent.OnKeyDown(key);
            } else {
                keyboardEvent.OnKeyUp(key);
            }

        }
        // Other program logic

        
    }
}

int main() 
{
    KeyboardEventHandler keyboardHandler;
    PollKeyboard(keyboardHandler);
    return 0;
}
