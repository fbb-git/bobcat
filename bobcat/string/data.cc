#include "string.ih"

bool (*String::s_FSAtransition[][s_nCharTypes])(FSAData &) = 
{
    //  DQUOTE, SQUOTE, SEPARATOR,  ESCAPE, CHAR,   EOS,
    {   &dqIn,  &sqIn,  &sepIn,     &escIn, &chIn,  &eosIn   },  // START
    {   &chIn,  &qEnd,  &chIn,      &chIn,  &chIn,  &eosSq   },  // SQSTRING
    {   &qEnd,  &chIn,  &chIn,      &escIn, &chIn,  &eosDq   },  // DQSTRING
};

// static
void String::strsep(SplitPairVector *entries)           // no action required
{}

void (*String::s_tuneToSplitType[])(SplitPairVector *entries) =
{
    &tok, 
    &toksep,
    &str,
    &strsep
};

string (*String::s_join[])(SplitPairVector const &entries, char sep)
{
    &joinIgnoreSEPARATOR,
    &joinAll
};
