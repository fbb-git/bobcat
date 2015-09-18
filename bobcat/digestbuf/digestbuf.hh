#include "digestbuf"

#include <iomanip>
#include <ostream>
#include <string>
#include <openssl/evp.h>

#include <bobcat/exception>

#include "../ohexstreambuf/ohexstreambuf"

namespace FBB
{
    
struct DigestBufImp
{
    EVP_MD_CTX    ctx;
    EVP_MD const *md;
    std::string   digest;
    char         *buffer;
    size_t        bufsize;

    DigestBufImp(size_t bufsize);
    ~DigestBufImp();                    // destructor.i
};

#include "destructor.f"

} // FBB

using namespace std;
using namespace FBB;

