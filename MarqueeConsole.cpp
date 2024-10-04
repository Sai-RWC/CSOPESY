#include <string>
#include <windows.h>
#include <cstdlib>
#include <iostream>

#include "MarqueeConsole.h"
#include "AConsole.h"
#include "ConsoleDriver.h"
#include "MarqueeWorker.h"


MarqueeConsole::MarqueeConsole() : AConsole(MARQUEE_CONSOLE)
{
    this->consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

}

void MarqueeConsole::onEnabled()
{
    this->showHeader();
}

void MarqueeConsole::display()
{
    // this->showHeader();
}

void MarqueeConsole::process()
{
    String sInput;
    KeyboardEventHandler keyboardHandler;
    this->showHeader();
    PollKeyboard(keyboardHandler);

    
    // std::getline(std::cin, sInput);
}

// TODO: cleanup Header file in Marqueeconsole
void MarqueeConsole::showHeader() const
{
    std::cerr << "*****************************************" << std::endl;
    std::cerr << "* Displaying a marquee console ! *" << std::endl;
    std::cerr << "*****************************************" << std::endl;
    // printf("%*s\n", fwidth, s);
}

