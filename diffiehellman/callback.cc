#include "diffiehellman.hh"

namespace {
    char info[] = {0, '.', '-', '+'};
}

void DiffieHellman::callback(int indicator, int, void *)
{
    if (indicator)
        cout.put(info[indicator]).flush();
}
