#include "configfile.ih"

bool ConfigFile__::rmCommentAndEscapes(string &line)
{
    size_t pos = 0;
    size_t lastBackslash = 0;

    while (true)
    {
        size_t hit;

                                            // change \\ to one backslash
        if ((hit = line.find("\\\\", pos)) != string::npos)
            line.erase(lastBackslash = hit, 1);
        else if ((hit = line.find("\\#", pos)) != string::npos)
            line.replace(hit, 2, "#");      // replace by #
        else 
        {
            if ((hit = line.find('#', pos)) != string::npos)
            {
                lastBackslash = string::npos;
                line.erase(hit);                // erase comment
            }

            if (line.length() > lastBackslash + 1 && *line.rbegin() == '\\')
            {
                line.resize(line.length() - 1);
                return true;
            }
            return false;                   
        }
        pos = hit + 1;                      // try again beyond the 
                                            // last-checked character
    }
}   
