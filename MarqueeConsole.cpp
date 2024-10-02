#include <string>
#include <windows.h>
#include <cstdlib>
#include <iostream>

#include "MarqueeConsole.h"
#include "AConsole.h"
#include "ConsoleDriver.h"
// #include "KeyboardHandler.h"


MarqueeConsole::MarqueeConsole() : AConsole(MARQUEE_CONSOLE)
{
    this->consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

}

void MarqueeConsole::onEnabled()
{
    this->display();
}

void MarqueeConsole::display()
{
    this->showHeader();
}

void MarqueeConsole::process()
{
    String sInput;
    KeyboardEventHandler keyboardHandler;
    ConsoleDriver::getInstance()->setCursorPosition(10, 10);
    PollKeyboard(keyboardHandler);
    // std::getline(std::cin, sInput);
}

void MarqueeConsole::showHeader() const
{
    // https://stackoverflow.com/questions/14921887/how-can-i-align-text-to-the-center-in-terminal
    std::cerr << "*****************************************" << std::endl;
    std::cerr << "* Displaying a marquee console ! *" << std::endl;
    std::cerr << "*****************************************" << std::endl;
    // printf("%*s\n", fwidth, s);
}

