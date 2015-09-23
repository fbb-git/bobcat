#include "process.hh"

void Process::rmBackticks()
{
    if (d_command.front() == '`' && d_command.back() == '`')  // rm backticks
    {
        d_command.resize(d_command.length() - 1);   // rm last backtick
        d_command.erase(0, 1);                      // rm front backtick
    }

}
