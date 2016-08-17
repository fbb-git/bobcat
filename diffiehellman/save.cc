#include "diffiehellman.ih"

    // save the prime, the generator, the public key, and the private key
void DiffieHellman::save(string const &basename, SecretKey action) const
{
    if (DH_generate_key(d_dh) == 0)
        throw Exception{} << "DiffieHellman::save: could not generate "
                                "public/private keys";

    BIGNUM const *g;
    DH_get0_pqg(d_dh, 0, 0, &g);
    DH_get0_key(d_dh, &d_pubKey, &d_privKey);
        
    int nBytes[] = 
            {
                static_cast<int>(d_prime.sizeInBytes()),         
                BN_num_bytes(g),
                BN_num_bytes(d_pubKey), 
                BN_num_bytes(d_privKey)
            };

    unique_ptr<char[]> dest(new char[*max_element(nBytes, nBytes + 4)]);

    ofstream out;
    Exception::open(out, basename + ".pub");
    
    write(out, &d_prime.bignum(),  dest.get(),   nBytes[0]);
    write(out, g,        dest.get(),   nBytes[1]);
    write(out, d_pubKey, dest.get(),   nBytes[2]);

    if (not out)
        throw Exception{} << "Could not write public DH info to `" << 
                             basename + ".pub'";

    if (action == DONT_SAVE_SECRET_KEY)
        return;

    out.close();
    Exception::open(out, basename + ".sec");

    write(out, d_privKey, dest.get(), nBytes[3]);

    if (not out)
        throw Exception{} << "Could not write private DH info to `" << 
                             basename + ".sec'";
}




