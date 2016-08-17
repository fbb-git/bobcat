#include "main.ih"

void handleErrors(void)
{
  ERR_print_errors_fp(stderr);
  throw 1;
}
