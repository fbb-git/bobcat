#include "milter.ih"

string Milter::s_name;
Milter *Milter::s_mp;
bool Milter::s_callClose;

unordered_map<SMFICTX *, Milter *> Milter::s_map;

