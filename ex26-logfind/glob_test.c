#include <stdio.h>
#include <glob.h>
#include "dbg.h"

int main(int argc, char *argv[])
{
  glob_t *pglob;
  int rc = glob("/home/user835/*common*", GLOB_MARK, NULL, pglob);
  check(rc == 0, "glob failed.");


  for (int i = 0; i < pglob->gl_pathc; i++)
  {
    printf("%s", pglob->gl_pathv[i]);
  }


  globfree(pglob);
  return 0;
error:
  if (pglob) globfree(pglob);
  return -1;
}
