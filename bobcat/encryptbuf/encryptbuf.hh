#include "encryptbuf"

#include <string>
#include <iomanip>
#include <ostream>
#include <algorithm>
#include <openssl/evp.h>

#include <bobcat/exception>
#include <bobcat/irandstream>

namespace FBB
{

struct EncryptBufImp
{
    EVP_CIPHER_CTX      ctx;
    EVP_CIPHER const   *md;
    bool                active;
    size_t              bufsize;
    char               *buffer;
    char               *out;
    std::string         iv;
    std::ostream       &outStream;

    EncryptBufImp(std::ostream &outStream, std::string const &iv, 
                  size_t bufsize);
    ~EncryptBufImp();                       // destructor.i

    static void setChar(char &ch, IRandStream &irs);

};

#include "destructor.f"

} // FBB

using namespace std;
using namespace FBB;





