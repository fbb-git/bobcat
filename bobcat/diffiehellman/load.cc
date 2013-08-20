#include "diffiehellman.ih"

bool DiffieHellman::load(istream &public)
{
    return 
        read(public, &dh->p) && 
        read(public, &dh->g) &&   
        read(public, &dh->pub_key);
}
