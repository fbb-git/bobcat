#include "diffiehellman.ih"

string DiffieHellman::key(std::string const &peerPublicFileName)
{
    ifstream in;
    Exception::open(in, peerPublicFileName);

    return key(in);
}
