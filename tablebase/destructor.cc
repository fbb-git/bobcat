#include "tablebase.ih"

TableBase::~TableBase()
{
    delete d_ptr;
}
