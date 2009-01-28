#include "main.ih"

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hv", argc, argv);
    arg.versionHelp(usage, Icmbuild::version, 1);

    size_t nTypes = A2x(argv[1]);

    if (nTypes <= 2)
    {
        cerr << "bobcat/lc will accept max. 3 rather than " << nTypes <<
                "types\n";
        nTypes = 3;
    }

    ofstream outf;
    if (arg.nArgs() > 1)
        Msg::open(outf, arg[1]);

    ostream out(arg.nArgs() == 1 ? cout.rdbuf() : outf.rdbuf());
    OFoldStream fold(out, 0, 79);

    fileOut(fold, "header");        // copy `header', all up to/including 
                                    // struct Unspecified

    lcBase(fold, nTypes);           // define the LCBase struct and
                                    // constructors 

    lc(fold, nTypes);               // define the LC struct and constructors

    fold <<  "} // FBB\n"           // end the header file (namespace and 
            "\n"                    // and include guard)
            "#endif\n";

    return 0;
}
catch (Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}
catch (...)
{
    return 1;
}
