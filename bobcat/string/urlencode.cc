#include "string.ih"

// after https://stackoverflow.com/questions/154536/encode-decode-urls-in-c

// static
string String::urlEncode(string const &text) 
{
    ostringstream escaped;
    escaped.fill('0');

    escaped << hex << uppercase;

    for (auto ch: text)
    {
        // Keep alphanumeric and other accepted characters intact
        if (isalnum(ch) || string{"-_.~"}.find(ch) != string::npos)
        {
            escaped.put(ch);
            continue;
        }

        // Any other characters are percent-encoded
        escaped << '%' << setw(2) << static_cast<int>(
                                            static_cast<unsigned char>(ch)
                                        );
    }

    return escaped.str();
}

