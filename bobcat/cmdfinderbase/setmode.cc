#include "cmdfinderbase.ih"

void CmdFinderBase::setMode(unsigned mode)
{
    if (mode & ~s_all)
        throw Errno(1, "CmdFinder: ") << insertable << "mode 0x" << hex << 
                          mode << " not recognized (allowed bits: 0x" << 
                          s_all << ")" << throwable;

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
