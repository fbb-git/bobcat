#include "diffiehellman.ih"

bool DiffieHellman::load(istream &publicData)
{
    return 
        read(publicData, &d_dh->p) && 
        read(publicData, &d_dh->g) &&   
        read(publicData, &d_dh->pub_key);
}
