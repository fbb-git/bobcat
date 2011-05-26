#include "mailheaders.ih"

void MailHeaders::read()
{
    static char funName[] = "MailHeaders::read()";

    if (size())
        throw Errno(funName) << "Mail headers already read";

    while (true)
    {
        string line;

        if (!getline(d_in, line))               // no more header lines
            throw Errno(funName) <<             // is an error condition
                "Headers incomplete after line " << d_lines.size();

        if (line.find_first_not_of(" \t") == string::npos)  // blank line
        {
            d_lines.resize(size() + 1);          // last line will be used as
                                                // the search sentinel
            return;
        }

        if (line[0] != ' ' && line[0] != '\t')  // add the new header line
            d_lines.push_back(line);
        else 
        {
            if (not d_lines.size())             // no header yet: error
                throw Errno(funName) << "Invalid begin of headers";
            (d_lines.back() += "\n") += line;   // add line continuation
        }
    }
}





