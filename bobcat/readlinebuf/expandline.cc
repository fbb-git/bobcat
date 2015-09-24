#include "readlinebuf.ih"

char *ReadLineBuf::expandLine()
{
    d_expansionError.clear();

    char *buf = readline(d_prompt.c_str());

    if (buf == 0)
        return 0;

    char *expanded;
    switch (d_expansion = static_cast<Expansion>(1 + 
                                       history_expand(buf, &expanded)))
    {
        case ERROR:
            d_expansionError = expanded;
        break;

        case NO_EXPANSION:
        break;

        default:
            std::swap(expanded, buf);
        break;
    }
    free(expanded);

    return nextLine(buf);
}


