#include "Process.h"

// TODO: complete missing fields or functions in the once requirements are specified

Process::Process(String nameIn) 
    : uid(newUID++)
{
    this->processName = nameIn;
    this->linesCode = 50;
}

int Process::getUid() 
{
    return this->uid;
}

int Process::getCurrentIL()
{
    return this->currentIL;
}

Process::String Process::getProcessName() const
{
    return this->processName;
}

int Process::getLinesCode()
{
    return this->linesCode;
}

int Process::newUID = 0;


// string getName() const {
//     return name;
// }
// };

