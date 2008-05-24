#include "pattern.ih"

void PerlSetFSA::copy()
{
    d_target += *d_next;
}

void PerlSetFSA::copybs()
{
    (d_target += "\\") += *d_next;
}

void PerlSetFSA::d_Set()
{
    d_target += "[[:digit:]]";
}
void PerlSetFSA::s_Set()
{
    d_target += "[[:space:]]";
}
void PerlSetFSA::w_Set()
{
    d_target += "[[:alnum:]]";
}

void PerlSetFSA::D_Set()
{
    d_target += "[^[:digit:]]";
}
void PerlSetFSA::S_Set()
{
    d_target += "[^[:space:]]";
}
void PerlSetFSA::W_Set()
{
    d_target += "[^[:alnum:]]";
}

void PerlSetFSA::d_Nest()
{
    d_target += "[:digit:]";
}
void PerlSetFSA::s_Nest()
{
    d_target += "[:space:]";
}
void PerlSetFSA::w_Nest()
{
    d_target += "[:alnum:]";
}


