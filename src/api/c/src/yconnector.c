#include "yconnector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *create_path(char **tokens, int n_tokens) {
  int len = 0;
  char *buff = NULL;
  for (int i = 0; i < n_tokens; i++) {
    len += (strlen(tokens[i]) + 2);
  }

  buff = calloc(len + 1, sizeof(char));
  if (buff == NULL)
    return NULL;

  for (int i = 0; i < n_tokens; i++) {
    char *b = calloc((strlen(tokens[i]) + 2), sizeof(char));
    if (i == n_tokens - 1)
      snprintf(b, (strlen(tokens[i]) + 1), "%s", tokens[i]);
    else
      snprintf(b, (strlen(tokens[i]) + 2), "%s/", tokens[i]);
    strncat(buff, b, strlen(b));
    free(b);
  }

  return buff;
}

char *create_selector(char **tokens, int n_tokens) {
  return create_path(tokens, n_tokens);
}
