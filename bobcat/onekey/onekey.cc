#include "onekey.ih"

OneKey::OneKey(Mode state)
{
    setEcho(state);

    if (!isatty(STDIN_FILENO))
        throw Errno(2, "OneKey::OneKey(): STDIN is not a tty");

    if (tcgetattr(STDIN_FILENO, &d_saved))
        throw Errno(2, 
                "OneKey::OneKey(): can't save the current stdin state");
    
    termios tattr;

    tcgetattr(STDIN_FILENO, &tattr);    // can't assign saved to tattr    

    tattr.c_lflag &= ~(ICANON | ECHO);
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr))
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &d_saved);
        throw Errno(1, 
            "OneKey::OneKey(): can't change the stdin state to direct input");
    }
}
