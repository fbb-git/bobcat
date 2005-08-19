#include "string.ih"

String String::trim() const
{
    std::string::size_type
        idx = find_first_not_of(" \t\r\n"); // find first non-ws

    if (idx == std::string::npos)                // only ws chars?
        return String();

    return substr(idx, find_last_not_of(" \t\r\n") - idx + 1);
}
