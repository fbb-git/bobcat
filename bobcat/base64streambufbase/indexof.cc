#include "base64streambufbase.hh"

size_t Base64StreambufBase::indexOf(int ch)
{
    size_t ret = s_tabStr.find(ch);

    if (ret == string::npos)
        throw "Infile not base64 encoded";

    return ret;
}
