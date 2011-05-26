#include "decryptbuf.ih"

DecryptBuf::~DecryptBuf()
{
    if (d_pimpl->active)
    try
    {
        done();
        s_completed = true;
    }
    catch(...)
    {
        s_completed = false;
    }
    delete d_pimpl;
}
