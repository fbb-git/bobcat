//                     usage.cc

#include "main.hh"

void usage(std::string  const  &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::year << "\n"
    "\n"
    "Usage: " << progname << " [options] npar [outfile]\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    "      --help (-h)      - provide this help\n"
    "      --version (-v)   - show version information and terminate\n"
    "   npar      - the max. number of parameters that can be used when\n"
    "               defining a local context.\n"
    "   outfile   - file to write the local context to (by default "
                                                            "stdout)\n" <<
    progname << " generates bobcat/lc, the header file defining the local\n"
    "   context struct (struct FBB::LC) generating templates\n"
    << endl;
}
