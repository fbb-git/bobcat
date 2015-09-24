#include "cgi.ih"

CGIFSA::CGIFSA(bool *escape, std::istream &in, bool setEscape)
:
    d_escape(escape),
    d_setEscape(setEscape),
    d_state(START),
    d_in(in)
{
    if (!s_installed)
    {
        std::for_each(s_fsaRawData, s_fsaRawDataEnd, setFsa);
        s_installed = true;
    }
}
