#include "configfile.ih"

bool ConfigFile::nextLine(istream &istr, string &line)
{
    size_t n_continuations;

    while (getline(istr, line))
    {
        ++d_rawIndex;                               // at the next line

        string::size_type pos = line.find_first_not_of(" \t");
        if (pos != string::npos)                    // remove initial ws.
            line.erase(0, pos);

        if (d_rmComment)
            removeComment(line);

        n_continuations = 0;
        while (true)
        {
            size_t lastChar = line.length() - 1;   // the last char
    
            if (line[lastChar] != '\\')             // not '\\' ?
                break;                              // then done here
                              
                                                    // got line continuation...
            line.erase(lastChar);                   // erase the last char
                                                    // append the next line
            n_continuations += append_next(istr, line);
        }

        if (hasContent(line))                       // any content on this?
        {
            removeTrailingBlanks(line);

            if (d_indices)
                d_index.push_back(d_rawIndex - n_continuations - 1);

            return true;
        }
    }
    line.erase();
    return false;                       // no more lines
}   
