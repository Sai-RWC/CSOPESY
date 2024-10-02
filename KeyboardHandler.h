#pragma once
#include <windows.h>

class IKeyboardEvent 
{
    public:
        virtual void OnKeyDown(char key) = 0;
        virtual void OnKeyUp(char key) = 0;
};

class KeyboardEventHandler : public IKeyboardEvent 
{
    public:
        void OnKeyDown(char key) override;
        void OnKeyUp(char key) override;
};

void PollKeyboard(IKeyboardEvent& keyboardEvent);
