inline void Xpointer::deleter(Display *dsp)
{
    if (dsp)
        XCloseDisplay(dsp);
}
