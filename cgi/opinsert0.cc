#include "cgi.ih"

std::ostream &FBB::operator<<(std::ostream &out, CGI const &cgi)
{
    for (int idx = 0; idx < 256; ++idx)
    {
        if (cgi.d_escape[idx])
        {
            if (isprint(idx))
                out << "'" << static_cast<char>(idx) << "'\n";
            else
                out << idx << endl;
        }
    }

    return out;
}
