#include "arg.ih"

Arg::Arg(char const *optstring, int argc, char **argv)
:
    d_argPointer(0)
{
    setBasename(argv[0]);

    string opts(*optstring == ':' ? "" : ":");  // ensure initial char is ':'
    opts += optstring;

    opterr = 0;                     // prevent getopt() msgs to stderr

    while (true)
    {
        int c = getopt(argc, argv, opts.c_str());

        switch (c)
        {
            case EOF:
                copy(argv + optind, argv + argc, back_inserter(d_argv));
            return;

            case ':':
                throw Errno(c, "ArgData::ArgData(): missing option value");
            return;

            case '?':
                throw Errno(optopt, "ArgData::ArgData(): unknown option");
            break;

            default:
                addCharOption(c);
            break;    
        }
    }
}


