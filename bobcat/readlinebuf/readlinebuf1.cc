#include "readlinebuf.ih"

ReadLineBuf::ReadLineBuf(string const &prompt, size_t historySize)
:
    d_prompt(prompt),
    d_history(historySize != 0),
    d_buffer(0)
{
    if (d_history)
    {
        using_history();
        if (historySize <= INT_MAX)
            stifle_history(historySize);
    }
}
