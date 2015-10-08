#include "milter.ih"

void Milter::initialize(string const &name, Milter &milter, 
                        callback_set callbacks, flag_set flags)
{
    if (s_mp)
        throw Exception(1) << 
                "Milter::initialize(): can't define multiple Milters";

    if (flags & ~ALL_FLAGS)
        throw Exception(1) <<  "Milter::initialize(): invalid flag(s): " << 
                                hex << (flags & ~ALL_FLAGS)<< dec;
    if (!callbacks)
        throw Exception(1) << "Milter::initialize(): no callbacks requested";

    if (callbacks & ~ALL_CALLBACKS)
        throw Exception(1) << 
                "Milter::initialize(): illegal callback(s) requested: " << 
                hex << (callbacks & ~ALL_CALLBACKS) << dec;

    struct smfiDesc descr = {const_cast<char *>(name.c_str()), 
                             SMFI_VERSION, flags, 0};
    
    s_name = name;
    s_mp = &milter;

    s_callClose = callbacks & CLOSE;        // Milter has its own close
                                            // function
    callbacks |= CLOSE;                     // always call mClose()

    for (size_t callback = 1; callback & ALL_CALLBACKS; callback <<= 1)
    {
        switch (callback & callbacks)
        {
            case CONNECT:
                descr.xxfi_connect = &mConnect;
            break;

            case HELO:
                descr.xxfi_helo = &mHelo;
            break;

            case SENDER:
                descr.xxfi_envfrom = &mSender;
            break;

            case RECIPIENT:
                descr.xxfi_envrcpt = &mRecipient;
            break;

            case HEADER:
                descr.xxfi_header = &mHeader;
            break;

            case EOH:
                descr.xxfi_eoh = &mEoh;
            break;

            case BODY:
                descr.xxfi_body = &mBody;
            break;

            case EOM:
                descr.xxfi_eom = &mEom;
            break;

            case ABORT:
                descr.xxfi_abort = &mAbort;
            break;

            case CLOSE:
                descr.xxfi_close = &mClose;
            break;
#if SMFI_VERSION > 2
            case UNKNOWN:
                descr.xxfi_unknown = &mUnknown;
            break;
#endif /* SMFI_VERSION > 2 */

#if SMFI_VERSION > 3
            case DATA:
                descr.xxfi_data = &mData;
            break;
#endif /* SMFI_VERSION > 3 */
        }
    }    

    if (smfi_register(descr) == MI_FAILURE)
        throw Exception() << "Milter::initialize(): defining Milter " << 
                                                    s_name << " failed";
}



