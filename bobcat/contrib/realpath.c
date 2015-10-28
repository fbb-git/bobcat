#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv)
{
    char *cp;

    if (argc == 1)          /* no arguments: give usage info */
    {
        printf("Provide %s with a (relative or absolute) path name: its "
                                                                "absolute\n"
                "path is written to the std. output stream (and the program\n"
                "returns 0)\n"
                "an empty string is written if the path could not be "
                                                            "determined\n"
                "in which case the program returns realpath(3)'s error "
                                                            "code\n", argv[0]);
        return 0;
    }

    cp = realpath(argv[1], 0);
    if (cp == 0)
        return errno;

    printf("%s\n", cp);
    free(cp);
    return 0;
}
