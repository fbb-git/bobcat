#include "main.ih"

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hv", argc, argv);
    arg.versionHelp(usage, Icmbuild::version, 1);

    ofstream outf;
    if (arg.nArgs() > 1)
        Msg::open(outf, arg[1]);

    ostream out(arg.nArgs() == 1 ? cout.rdbuf() : outf.rdbuf());
    
    size_t nTypes = A2x(argv[1]);

    fileOut(out, "header");
    lcBase(out, nTypes);
    lc(out, nTypes);

    out <<  "} // FBB\n"
            "\n"
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
