#include "tablebase.hh"

TableBase::~TableBase()
{
    delete d_ptr;
}
