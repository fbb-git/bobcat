//                     usage.cc

#include "main.ih"

namespace
{
    Pattern pattern("([^=]*)=(.*)");
}

void usage(std::string  const  &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::year << "\n"
    "\n"
    "Usage: " << progname << " [options] args\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    "      -e               - show the environment variables that were set\n"
    "      -m<size>[bkmg]   - max uploadsize to use\n"
    "      -h               - provide this help\n"
    "      -v               - show version information and terminate\n"
    "   args                - 1st arg: file defining envvars (see `get' and\n"
    "                                                               `post')\n"
    "                         2nd args: RE defining characters to escape.\n"
    << endl;
}
