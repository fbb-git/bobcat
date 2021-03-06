#include "arg.ih"

Arg__::Arg__(char const *optstring, 
         LongOption const * const begin, LongOption const * const end,
         int argc, char **argv)
:
    d_argPointer(0),
    d_beyondDashes(find(argv, argv + argc, string("--")) - argv)
{
    setBasename(argv[0]);

    string opts(*optstring == ':' ? "" : ":");  // ensure initial char is ':'
                                    // (returns : when a required argument is
                                    // missing)
    opts += optstring;

    OptStructArray optStructs(end - begin + 1); // create array of n + 1 
                                                // structs for long options

    fillLongOptions(optStructs.get(), optstring, begin, end);

    opterr = 0;                // prevent getopt() msgs to stderr
    int longOptionIndex;       // receives the index of the long options

    while (true)
    {
        d_getOpt = getopt_long(argc, argv, opts.c_str(), optStructs.get(), 
                                                         &longOptionIndex);

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

            case 0:
                if (plainLongOption(begin[longOptionIndex]))
                    break;

            [[fallthough]]
            // FALLING THROUGH IF LONG OPTION IS ALSO SHORT CHAR OPTION
                // in which case d_getOpt is set to the corresponding short
                // char option

            default:
                addCharOption();
            break;    
        }
    }
}

Arg::Arg(char const *optstring, 
         LongOption const * const begin, LongOption const * const end,
         int argc, char **argv)
:
    d_ptr(new Arg__(optstring, begin, end, argc, argv))
{
    d_ptr->verify();
}
