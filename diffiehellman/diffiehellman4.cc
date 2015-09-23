#include "diffiehellman.hh"

DiffieHellman::DiffieHellman(string const &publicFileName,
                             string const &privateFileName)
:
    DiffieHellman(*unique_ptr<istream>(new ifstream(publicFileName)),
                  *unique_ptr<istream>(new ifstream(privateFileName)))
{}







