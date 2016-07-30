#include "diffiehellman.ih"

void DiffieHellman::save(string const &basename, SecretKey action) const
{
    if (DH_generate_key(d_dh) == 0)
        throw Exception{} << "DiffieHellman::save: could not generate "
                                "public/private keys";

    BIGNUM const *p;
    BIGNUM const *g;

    DH_get0_pqg(d_dh, &p, 0, &g);
    
    BIGNUM const *pub_key;
    BIGNUM const *priv_key;
    DH_get0_key(d_dh, &pub_key, &priv_key);
        
    int nBytes[] = 
            {
                BN_num_bytes(p),       BN_num_bytes(g),
                BN_num_bytes(pub_key), BN_num_bytes(priv_key)
            };

    unique_ptr<char[]> dest(new char[*max_element(nBytes, nBytes + 4)]);

    ofstream out;
    Exception::open(out, basename + ".pub");
    
    write(out, p,       dest.get(),   nBytes[0]);
    write(out, g,       dest.get(),   nBytes[1]);
    write(out, pub_key, dest.get(),   nBytes[2]);

    if (not out)
        throw Exception{} << "Could not write public DH info to `" << 
                             basename + ".pub'";

    if (action == DONT_SAVE_SECRET_KEY)
        return;

    out.close();
    Exception::open(out, basename + ".sec");

    write(out, priv_key, dest.get(), nBytes[3]);

    if (not out)
        throw Exception{} << "Could not write private DH info to `" << 
                             basename + ".sec'";
}




