#include "readlinebuf.ih"

ReadLineBuf::ReadLineBuf(string const &prompt, size_t historySize, Type type)
:
    d_history(historySize > 0),
    d_prompt(prompt),
    d_buffer(0),
    d_readline(&ReadLineBuf::readLine),
    d_timestamp(0)
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
        stifle_history(
            historySize > static_cast<size_t>(numeric_limits<int>::max()) ? 
                numeric_limits<int>::max() 
                    : 
                historySize
        );
    }
}
