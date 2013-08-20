#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(string const &initiatorPublicFileName)
:
    d_dh(0, DH_free)
{
    ifstream in;
    Exception::open(in, initiatorPublicFileName);

    if (not load(in))
        throw Exception() << s_header << 
                            "could not load public values from " <<
                            initiatorPublicFileName;

    checkDHparameters();    
}










