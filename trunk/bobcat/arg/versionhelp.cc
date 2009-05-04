#include "arg.ih"

void Arg::versionHelp(void (*usage)(string const &progname), 
        char const *version, size_t minArgs, int helpFlag, 
        int versionFlag) const
{
    if (option(versionFlag) && !option(helpFlag))
    {
        cout << basename() << " V" << version << endl;
        throw 1;
    }

    if (nArgs() < minArgs || option(helpFlag))
    {
        usage(basename());
        throw 1;
    }
}
