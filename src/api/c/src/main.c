#include "yconnector.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  const char *a[3];
  a[0] = GLOBAL_ACTUAL_PREFIX;
  a[1] = "blah";
  a[2] = "hmm";

  char *res = NULL;
  res = create_path(a, 3);
  printf("RES1: %s\n", res);

  res = create_selector(a, 3);
  printf("RES2: %s\n", res);
  exit(0);
}
