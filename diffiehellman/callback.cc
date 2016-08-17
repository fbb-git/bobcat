#include "diffiehellman.ih"

namespace {
    char info[] = {0, '.', '-', '+'};
}

int DiffieHellman::callback(int indicator, int, BN_GENCB *)
{
    if (indicator)
        cout.put(info[indicator]).flush();
    return 1;
}
