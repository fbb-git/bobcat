#include "diffiehellman.hh"

DiffieHellman::DiffieHellman(string const &initiatorPublicFileName)
:
    DiffieHellman(*unique_ptr<istream>(new ifstream(initiatorPublicFileName)))
{}










