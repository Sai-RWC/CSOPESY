#pragma once
#include "AConsole.h"
#include "KeyboardHandler.h"

static constexpr int REFRESH_DELAY = 10;
static constexpr int POLLING_DELAY = 5;

class MarqueeConsole : public AConsole 
{
public:
    MarqueeConsole();
    ~MarqueeConsole() = default;
    void onEnabled() override;
    void process() override;
    void display() override;
    void showHeader() const;
    HANDLE consoleHandle;
private:
};
