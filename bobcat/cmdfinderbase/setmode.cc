#include "cmdfinderbase.ih"

void CmdFinderBase::setMode(size_t mode)
{
    if (mode & ~s_all)
        throw Exception(1) << "CmdFinder: " << "mode 0x" << hex << mode << 
                        " not recognized (allowed bits: 0x" << s_all << ")";

    d_useCmd = mode & USE_FIRST ? 
                    &CmdFinderBase::useFirstCmd  
                :
                    &CmdFinderBase::useCmd;

    switch (mode & (UNIQUE | INSENSITIVE))
    {
        case 0:
            d_match = &CmdFinderBase::matchExact;
        break;
        case UNIQUE:
            d_match = &CmdFinderBase::matchUnique;
        break;
        case INSENSITIVE:
            d_match = &CmdFinderBase::matchInsensitive;
        break;
        default:
            d_match = &CmdFinderBase::matchUniqueInsensitive;
        break;
    }
}
