#pragma once
#include "AConsole.h"
#include "MarqueeWorker.h"



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
