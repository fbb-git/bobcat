#include "main.ih"

void fileOut(ostream &out, char const *fname)
{
    ifstream in;
    Msg::open(in, fname);
    out << in.rdbuf();
}




