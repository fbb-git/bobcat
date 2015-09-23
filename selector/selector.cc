/*
                              selector.cc
*/

#include "selector.hh"

Selector::Selector()
{
    FD_ZERO(&d_read);
    FD_ZERO(&d_write);
    FD_ZERO(&d_except);

    noAlarm();

    d_max = 0;
}

