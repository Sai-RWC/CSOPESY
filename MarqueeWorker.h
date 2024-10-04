#pragma once
#include <windows.h>

static constexpr int REFRESH_DELAY = 5;
static constexpr int POLLING_DELAY = 5;

static constexpr int XBOUNDS = 120;
static constexpr int YBOUNDS_MAX = 25;
static constexpr int YBOUNDS_MIN = 3;


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
void printHeader();