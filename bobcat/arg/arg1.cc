#include "arg.ih"

Arg__::Arg__(char const *optstring, int argc, char **argv)
:
    d_argPointer(0),
    d_beyondDashes(find(argv, argv + argc, string("--")) - argv)
{
    setBasename(argv[0]);

    string opts(*optstring == ':' ? "" : ":");  // ensure initial char is ':'
                                    // (returns : when a required argument is
                                    // missing)
    opts += optstring;

    opterr = 0;                     // prevent getopt() msgs to stderr

    while (true)
    {
        d_getOpt = getopt(argc, argv, opts.c_str());

        switch (d_getOpt)
        {
            case -1:
                d_beyondDashes += (d_beyondDashes != argc) - optind;
                copy(argv + optind, argv + argc, back_inserter(d_argv));
            return;

            case ':':
                s_optChar[0] = optopt;
                d_msg = (optopt ? s_optChar : argv[optind - 1]);
            return;

            case '?':
                s_optChar[0] = optopt;
                d_msg = (optopt ? s_optChar : argv[optind - 1]);
            return;

            default:
                addCharOption();
            break;    
        }
    }
}


Arg::Arg(char const *optstring, int argc, char **argv)
:
    d_ptr(new Arg__(optstring, argc, argv))
{
    d_ptr->verify();
}

