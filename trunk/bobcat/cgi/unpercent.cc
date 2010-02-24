#include "cgi.ih"

std::string CGI::unPercent(std::string const &text)
{
    string ret(text);
    string::size_type pos = 0;
    string sub;
    char replacement[2] = {0, 0};

    while (true)
    {
        pos = ret.find_first_of("+%", pos);

        if (pos == string::npos)        // none found
            break;

        if (ret[pos] == '+')            // convert '+'
            ret[pos] = ' ';
        //                              // viable % found
        else if ((sub = ret.substr(pos + 1, 2)).length() == 2)
        {            
            istringstream convert(sub);
            size_t value;
            if (convert >> hex >> value)    // successfully converted
            {
                replacement[0] = value;
                ret.replace(pos, 3, replacement);
            }
        }
        ++pos;                          // next char
    }        
    return ret;
}


