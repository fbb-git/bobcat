#include "diffiehellman.ih"

void DiffieHellman::save(string const &basename, SecretKey action) const
{
    if (DH_generate_key(d_dh.get()) == 0)
        throw Exception() << "DiffieHellman::save: could not generate "
                                "public/private keys";
        
    int nBytes[] = 
            {
                BN_num_bytes(d_dh->p),       BN_num_bytes(d_dh->g),
                BN_num_bytes(d_dh->pub_key), BN_num_bytes(d_dh->priv_key)
            };

    unique_ptr<char[]> dest(new char[*max_element(nBytes, nBytes + 4)]);

    ofstream out;
    Exception::open(out, basename + ".pub");
    
    write(out, d_dh->p, dest.get(),         nBytes[0]);
    write(out, d_dh->g, dest.get(),         nBytes[1]);
    write(out, d_dh->pub_key, dest.get(),   nBytes[2]);

    if (not out)
        throw Exception() << "Could not write public DH info to `" << 
                             basename + ".pub'";

    if (action == DONT_SAVE_SECRET_KEY)
        return;

    out.close();
    Exception::open(out, basename + ".sec");

    write(out, d_dh->priv_key, dest.get(), nBytes[3]);

    if (not out)
        throw Exception() << "Could not write private DH info to `" << 
                             basename + ".sec'";
}


