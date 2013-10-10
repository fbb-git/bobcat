inline DecryptBufImp::~DecryptBufImp()
{
    delete [] buffer;
    delete [] out;
}
