#include "msg.ih"

char const *Msg::s_warning = "[Warning] ";
bool Msg::s_display = true;
size_t Msg::s_line;
size_t Msg::s_warnCount;
size_t Msg::s_count;
size_t Msg::s_maxCount = UINT_MAX;

ostringstream Msg::s_msg;

Msg::StreamInfo Msg::s_streams[Msg::s_sizeofType];

size_t const Msg::s_nStreams = 
                        sizeof(Msg::s_streams) / sizeof(Msg::StreamInfo);
