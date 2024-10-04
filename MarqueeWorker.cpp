#include <conio.h>
#include <iostream>
#include <sstream>
#include <queue>

#include "MarqueeWorker.h"
#include "ConsoleDriver.h"


String commandHist = "";
String sInput = "";
//INT COLS, ROWS;

BOOL up = false, forward = true, running = true;

int x = 1;
int y = YBOUNDS_MIN + 1;

int xCursor = 37;

HANDLE hStdOut = ConsoleDriver::getInstance()->getConsoleHandle();



void KeyboardEventHandler::OnKeyDown(char key)
{
    std::cout << "Key Down: " << key << std::endl;
}

void KeyboardEventHandler::OnKeyUp(char key)
{
    std::cout << "Key Up: " << key << std::endl;
}

void printHeader()
{
    std::cerr << "*****************************************" << std::endl;
    std::cerr << "* Displaying a marquee console ! *" << std::endl;
    std::cerr << "*****************************************" << std::endl;
    // printf("%*s\n", fwidth, s);
}

void setDirX()
{
    if (x == XBOUNDS)
    {
        forward = false;
    }
    if (x == 0)
    {
        forward = true;
    }
    if (x < XBOUNDS && forward)
    {
        x = x + 1;
    }
    else if (x > 0 && !forward)
    {
        x = x - 1;
    }

}

void setDirY()
{

    if (y == YBOUNDS_MIN)
    {
        up = false;
    }
    if (y == YBOUNDS_MAX)
    {
        up = true;
    }
    if (y > 0 && up)
    {
        y = y - 1;
    }
    else if (y < YBOUNDS_MAX && !up)
    {
        y = y + 1;
    }
}


void PollKeyboard(IKeyboardEvent& keyboardEvent)
{
    while (running) {

        // test
        ConsoleDriver::getInstance()->setCursorPosition(0, 0);
        printHeader();
        
        ConsoleDriver::getInstance()->setCursorPosition(x, y);
        setDirX();
        setDirY();
        std::cout << "Hello world in marquee!";
        ConsoleDriver::getInstance()->setCursorPosition(0, YBOUNDS_MAX+1);
        std::cout << "Enter a command for MARQUEE_CONSOLE: " << sInput;
        std::cout << commandHist;
        ConsoleDriver::getInstance()->setCursorPosition(xCursor, YBOUNDS_MAX+1 );
        
        Sleep(POLLING_DELAY);
     
        if (_kbhit()) {
            char key = _getch();
            if (GetAsyncKeyState(key) & 0x8000) {
                //keyboardevent.onkeydown(key);
                if (key == '\r' || key == '\n')
                {
                    commandHist = commandHist + "\n" + "Command processed in MARQUEE_CONSOLE: " + sInput;
                    sInput = "";
                    if (!sInput.compare("exit"))
                    {
                        running = false;
                        ConsoleDriver::getInstance()->returnToPreviousConsole();
                    }
                    xCursor = 37;
                }
                if (key == '127' || key == 8 && xCursor > 37)
                {
                    xCursor = xCursor - 1;
                    sInput.pop_back();
                }
                // std::cout << "Key Down: " << key << std::endl;
            }
            else {
                //keyboardEvent.OnKeyUp(key);
                // std::cout << "Key Up: " << key << std::endl;
                if (key == '\r' || key == '\n')
                {
                    commandHist = commandHist + "\n" + sInput;
                    sInput = "";
                    xCursor = 37;
                    if (sInput == "exit")
                    {
                        running = false;
                    }
                }
                sInput = sInput + key;
                xCursor = xCursor + 1;
            }

        }
        Sleep(REFRESH_DELAY);
        system("CLS");
    }
}