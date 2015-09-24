#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(string const &initiatorPublicFileName)
:
    DiffieHellman(*unique_ptr<istream>(new ifstream(initiatorPublicFileName)))
{}










