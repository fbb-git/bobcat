#include "stat.ih"

string Stat::typeStr() const
{
    string ret;

    switch (type())
    {
        case BLOCK_DEVICE:
            ret = "BLOCK_DEVICE";
        break;
        case CHARACTER_DEVICE:
            ret = "CHARACTER_DEVICE";
        break;
        case DIRECTORY:
            ret = "DIRECTORY";
        break;
        case FIFO:
            ret = "FIFO";
        break;
        case REGULAR_FILE:
            ret = "REGULAR_FILE";
        break;
        case SOCKET:
            ret = "SOCKET";
        break;
        case SYMBOLIC_LINK:
            ret = "SYMBOLIC_LINK";
        break;
    }

    return ret;
}


    
