#include "configfile.ih"

#include "../iuo/iuo"

ConfigFile::ConfigFile(ConfigFile const &&tmp)
:
    d_line( move(tmp.d_line) ),

    d_rmComment(tmp.d_rmComment),
    d_caseSensitive(tmp.d_caseSensitive),
    d_indices(tmp.d_indices),
    d_rawIndex(tmp.d_rawIndex),

    d_index( move(tmp.d_index) ),
    d_vsIter( move(tmp.d_vsIter) ),
    d_re( move(tmp.d_re) ),
    d_pattern( move(tmp.d_pattern) )
{
    static bool called = false;
    deprecated__(called, "ConfigFile::ConfigFile(ConfigFile const &&tmp)");
}
