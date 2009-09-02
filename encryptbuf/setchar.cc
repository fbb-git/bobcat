#include "encryptbuf.ih"

void EncryptBufImp::setChar(char &ch, IRandStream &irs)
{
    int value;
    irs >> value;
    ch = value;
}
