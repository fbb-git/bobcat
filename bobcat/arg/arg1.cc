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
        d_getOpt = getopt(argc, argv, opts.c_str());

        switch (d_getOpt)
        {
            case EOF:
                copy(argv + optind, argv + argc, back_inserter(d_argv));
            return;

            case ':':
                s_optChar[0] = optopt;
                d_optErr = (optopt ? s_optChar : argv[optind - 1]);
            return;

            case '?':
                s_optChar[0] = optopt;
                d_optErr = (optopt ? s_optChar : argv[optind - 1]);
            return;

            default:
                addCharOption();
            break;    
        }
    }
}


