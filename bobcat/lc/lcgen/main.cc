#include "main.ih"

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hv", argc, argv);
    arg.versionHelp(usage, Icmbuild::version, 1);

    FoldStream fold(0, 80);

    ofstream outf;
    if (arg.nArgs() > 1)
        Msg::open(outf, arg[1]);

    ostream out(arg.nArgs() == 1 ? cout.rdbuf() : outf.rdbuf());

    fold.open(out);
     
    size_t nTypes = A2x(argv[1]);

    fileOut(fold, "header");
    lcBase(fold, nTypes);
    lc(fold, nTypes);

    fold <<  "} // FBB\n"
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
