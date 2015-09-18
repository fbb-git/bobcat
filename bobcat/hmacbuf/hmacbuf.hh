#include "hmacbuf"

#include <string>
#include <openssl/hmac.h>
#include <ostream>

#include <bobcat/exception>
#include "../ohexstreambuf/ohexstreambuf"

namespace FBB
{

struct HMacBufImp
{
    HMAC_CTX      ctx;
    EVP_MD const *md;
    std::string   digest;
    char         *buffer;
    size_t        bufsize;
    std::string   key;

    HMacBufImp(std::string const &key, size_t bufsize);
    ~HMacBufImp();                                      // destructor.i
};

#include "destructor.f"

} // FBB

using namespace std;
using namespace FBB;
