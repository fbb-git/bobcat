#include "ofoldstreambuf.hh"

void OFoldStreambuf::iniBlankTabs(TabsOrBlanks tob)
{
    if (tob == BLANKS)
        useBlanks();
    else
        useTabs();
}
