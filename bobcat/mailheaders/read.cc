#include "mailheaders.ih"

void MailHeaders::read()
{
    static char funName[] = "MailHeaders::read()";

    if (size())
        Errno(funName) << insertable <<
                        "Mail headers already read" << throwable;

    while (true)
    {
        string line;

        if (!getline(d_in, line))               // no more header lines
            Errno(funName) << insertable <<     // is an error condition
                "Headers incomplete after line " << 
                size() << throwable;

        if (line.find_first_not_of(" \t") == string::npos)  // blank line
        {
            resize(size() + 1);                 // last line will be used as
                                                // the search sentinel
            return;
        }

        if (line[0] != ' ' && line[0] != '\t')  // add the new header line
            push_back(line);
        else 
        {
            if (not size())                     // no header yet: error
                Errno(funName) << insertable <<
                "Invalid begin of headers"  << throwable;
            (back() += "\n") += line;           // add line continuation
        }
    }
}





