#include "msg.ih"

char const *Msg::s_warning = "[Warning] ";
bool Msg::s_display;
size_t Msg::s_line;
size_t Msg::s_warnCount;
size_t Msg::s_count;
size_t Msg::s_maxCount = UINT_MAX;
ostringstream Msg::s_msg;
ostream Msg::s_out(cout.rdbuf());
ostream Msg::s_info(cout.rdbuf());
ofstream Msg::s_fout;

