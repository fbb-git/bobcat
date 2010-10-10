#include "readlinebuf.ih"

ReadLineBuf::ReadLineBuf(string const &prompt, size_t historySize, Type type)
:
    d_history(historySize > 0),
    d_prompt(prompt),
    d_buffer(0),
    d_readline(&ReadLineBuf::readLine)
{
    if (!d_history)
    {
        if (type == EXPAND_HISTORY)
            throw std::logic_error("Can't EXPAND_HISTORY without history");
    }
    else
    {
        if (type == EXPAND_HISTORY)
            d_readline = &ReadLineBuf::expandLine;
        using_history();
        stifle_history(historySize > INT_MAX ? INT_MAX : historySize);
    }
}
