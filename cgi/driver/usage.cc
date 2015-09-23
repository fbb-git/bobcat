//                     usage.cc

#include "main.hh"

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
    "Usage: " << progname << " [options] arg to-escape < arg.cin\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    "      -e               - show the environment variables that were set\n"
    "      -m<size>[bkmg]   - max uploadsize to use\n"
    "      -h               - provide this help\n"
    "      -v               - show version information and terminate\n"
    "   arg                 - file defining envvars\n"
    "                         (see, e.g.,  `get' and `post1')\n"
    "   to-escape           - RE defining characters to escape.\n"
    "                         (e.g., '[:cgi:]')\n"
    "   < arg.cin           - file to read, simulating form-output\n"
    "                         (e.g., post1.cin)\n" 
    "   For the 'get' method the input redirection is not used/required\n"
    "\n";
}

