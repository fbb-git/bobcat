#include "readlinebuf.ih"

ReadLineBuf::ReadLineBuf(size_t historySize, string const &prompt)
:
    d_history(historySize > 0),
    d_prompt(prompt),
    d_buffer(0)
{
    if (d_history)
    {
        using_history();
        stifle_history(historySize > INT_MAX ? INT_MAX : historySize);
    }
}
