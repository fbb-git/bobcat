#include "csv4180.ih"

bool (CSV4180::*CSV4180::s_fsa[][nCharTypes])() = 
{
    //  EOLN            CR                  CHAR                DQUOTE              FIELDSEP   
  
    {   &CSV4180::end,  &CSV4180::toCr,     &CSV4180::addCh,    &CSV4180::toDq1,    &CSV4180::field  }, // START
    {   &CSV4180::end,  &CSV4180::err,      &CSV4180::err,      &CSV4180::err,      &CSV4180::err,   }, // CRSTATE
    {   &CSV4180::end,  &CSV4180::toCr,     &CSV4180::addCh,    &CSV4180::err,      &CSV4180::field  }, // CHARSTATE
    {   &CSV4180::req,  &CSV4180::addDq1,   &CSV4180::addDq1,   &CSV4180::toDq2,    &CSV4180::addDq1 }, // DQ1
    {   &CSV4180::end,  &CSV4180::toCr,     &CSV4180::err,      &CSV4180::addDq1,   &CSV4180::field  }, // DQ2
};
