#include "bigint"

#include <cstring>
#include <cctype>
#include <algorithm>

#include <openssl/ui.h>
#include <bobcat/exception>
#include <bobcat/fswap>

namespace FBB
{

class BNCTX
{
    BN_CTX *d_ctx;

    public:
        BNCTX();                                    // .i
        ~BNCTX();                                   // destructor.i
        void verify();

        operator BN_CTX *();                        // opbnctxptr.i

    private:
        BNCTX(BNCTX const &other) = delete;
        BNCTX &operator=(BNCTX const &other) = delete;
};

#include "bnctx.f"
#include "destructor.f"
#include "opbnctxptr.f"

} // namespace FBB
        
using namespace std;
using namespace FBB;
