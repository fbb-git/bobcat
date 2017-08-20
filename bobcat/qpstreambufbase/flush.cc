#include "qpstreambufbase.ih"

void QPStreambufBase::flush()
{
    if (d_pending.empty())              // empty line
        return;

    unsigned char ch = d_pending.back();

    if (isblank(ch))                    // escape final blank
    {
        d_pending.pop_back();
        escape(ch);
    }

    size_t pos;
    while (d_pending.length() > MAX_LENGTH)     // split long lines
    {
        pos = d_pending.find_last_of(" \t", LAST_IDX - 1);
        if (pos != string::npos)                // found a blank
        {
            ++pos;
            d_buffer.append(d_pending, 0, pos);
            d_buffer += "=\n";
            d_pending.erase(0, pos);
            continue;
        }

        pos = d_pending.find_last_of('=', LAST_IDX);    // find an esc. seq.
        if (pos == string::npos || pos <= LAST_IDX - 3) // not at the end
            pos = LAST_IDX;

        d_buffer.append(d_pending, 0, pos);
        d_buffer += "=\n";
        d_pending.erase(0, pos);
    }

    d_buffer += d_pending;
    d_pending.clear();            
}

