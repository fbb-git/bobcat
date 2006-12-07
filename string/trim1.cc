#include "string.ih"

string String::trim(string const &str)
{
    std::string::size_type
        idx = str.find_first_not_of(" \t\r\n"); // find first non-ws

    if (idx == std::string::npos)                // only ws chars?
        return string();

    return str.substr(idx, str.find_last_not_of(" \t\r\n") - idx + 1);
}
