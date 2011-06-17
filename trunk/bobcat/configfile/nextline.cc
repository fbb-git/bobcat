#include "configfile.ih"

bool ConfigFile::nextLine(istream &istr, string &line)
{
    size_t n_continuations;

    while (getline(istr, line))
    {
        ++d_rawIndex;                               // at the next line

                                                    // remove initial ws.
        string::size_type pos = line.find_first_not_of(" \t");
        if (pos != string::npos)
            line.erase(0, pos);

        if (d_rmComment)
            removeComment(line);

                                                    // process lines ending
                                                    // in a backslash
        n_continuations = 0;
        while (size_t lastIdx = line.length())      // as long as there are
        {                                           // characters

            --lastIdx;                              // set lastIdx to idx of 
                                                    // last ch.
    
            if (line[lastIdx] != '\\')              // last not \ ?
                break;                              // then done here
                              
                                                    // got line continuation...

            line.resize(lastIdx);                   // erase the last char

                                                    // append the next line
            n_continuations += append_next(istr, line);
        }

        if (hasContent(line))                       // any contents on this?
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
