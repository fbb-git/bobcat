#include "configfile.ih"

bool ConfigFile__::nextLine(istream &inStream, string &dest)
{
    dest.erase();
    string line;

    while (getline(inStream, line))
    {
        ++d_rawIndex;                               // at the next line

        trimLeft(line);

        bool appendNext = rmCommentAndEscapes(line);

        trimRight(line, appendNext);

        dest += line;
        if (not appendNext)
            return true;
    }

    return dest.length();
}

