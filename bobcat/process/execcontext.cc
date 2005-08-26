#include "process.ih"

void Process::execContext(String::SplitPair const &splitPair,
                                ExecContext &ec)
{
    if (!ec.ok)                 // once a problem was detected, stop working
        return;

    switch (splitPair.second)
    {
        case String::DQUOTE_UNTERMINATED:
            ec.message = "Unterminated double-quoted argument";
            ec.ok = false;
        break;

        case String::SQUOTE_UNTERMINATED:
            ec.message = "Unterminated single-quoted argument";
            ec.ok = false;
        break;

        case String::ESCAPED_END:
            ec.message = "Incomplete argument (ending in \\)";
            ec.ok = false;
        break;

        case String::SEPARATOR:// doesn't happen, but prevents a compiler
        break;                 // warning

        case String::NORMAL:
        case String::DQUOTE:
        {
                    // allocated, and not deleted, but that's irrelevant,
                    // the arguments are used in the child process which is 
                    // performing an exec() anyway.
            String *sp = new String(String(splitPair.first).unescape());
            ec.args[ec.argc++] = sp->c_str();
        }
        break;

        case String::SQUOTE:
            ec.args[ec.argc++] = splitPair.first.c_str();
        break;
    }
}
