#include "onekey.ih"

OneKey::OneKey(Mode state, bool)
:
    d_err(0)
{
    setEcho(state);

    if (!isatty(STDIN_FILENO))
    {
        setErr(2, "OneKey::OneKey(): STDIN is not a tty");
        return;
    }

    if (tcgetattr(STDIN_FILENO, &d_saved))
    {
        setErr(2, "OneKey::OneKey(): can't save the current stdin state");
        return;
    }
    
    termios tattr;

    tcgetattr(STDIN_FILENO, &tattr);    // can't assign saved to tattr    

    tattr.c_lflag &= ~(ICANON | ECHO);
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr))
        setErr(1, "OneKey::OneKey(): can't change the stdin state to "
                                                              "direct input");
}
