#include "decryptbuf"

#include <string>
#include <openssl/evp.h>

#include <bobcat/exception>

namespace FBB
{

struct DecryptBufImp
{
    EVP_CIPHER_CTX      ctx;
    EVP_CIPHER const   *md;
    bool                active;
    size_t              bufsize;
    char               *buffer;
    char               *out;
    std::ostream       &outStream;

    DecryptBufImp(std::ostream &outStream, size_t bufsize);
    ~DecryptBufImp();                       // destructor.i
};

#include "destructor.f"

} // FBB

using namespace std;
using namespace FBB;
