#include "csv.ih"

std::ostream &(CSV::*CSV::s_insert[])(std::ostream &out) const = 
    {
        &CSV::insertLength,
        &CSV::insertSize,
        &CSV::insertCount,
    };
