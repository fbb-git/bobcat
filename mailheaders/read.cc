#include "mailheaders.ih"

#ifndef _SYSINC_IOSTREAM_
#include <iostream>
#define _SYSINC_IOSTREAM_
#endif

void MailHeaders::read()
{
    static char funName[] = "MailHeaders::read()";

    if (size())
        Errno(funName) << insertable <<
                        "Mail headers already read" << throwable;

    HdrLine *hdrLine = 0;
    while (true)
    {
        string line;

        if (!getline(d_in, line))           // no more header lines
            Errno(funName) << insertable <<    // is an error condition
                "Headers incomplete after line " << 
                size() << throwable;

        if (line.find_first_not_of(" \t") == string::npos)  // blank line
        {
            push_back(line);                        // store the header line
            break;                                  // then done
        }

        if (!isspace(line[0]))                      // new header line
            hdrLine = startHeader(line);
        else
            continueHeader(line, hdrLine);

        push_back(line);                            // store the header line
    }
}





