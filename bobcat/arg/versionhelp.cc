#include "arg.ih"

void Arg__::versionHelp(void (*usage)(string const &progname), 
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

void Arg::versionHelp(void (*usage)(string const &progname), 
        char const *version, size_t minArgs, int helpFlag, 
        int versionFlag) const
{
    return d_arg->versionHelp(usage, version, minArgs, helpFlag, versionFlag);
}
