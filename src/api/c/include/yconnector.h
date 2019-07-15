#ifndef YAKS_CONNECTOR
#define YAKS_CONNECTOR

#define DEFAULT_SYSTEM "0"
#define DEFAULT_TENANT "0"

#define GLOBAL_ACTUAL_PREFIX "/agfos"
#define GLOBAL_DESIRED_PREFIX "/dgfos"
#define LOCAL_ACTUAL_PREFIX "/alfos"
#define LOCAL_DESIRED_PREFIX "/dlfos"
#define LOCAL_CONSTRAINED_ACTUAL_PREFIX "/aclgfos"
#define LOCAL_CONSTRAINED_DESIRED_PREFIX "/dclfos"

char *create_path(char **tokens, int n_tokens);
char *create_selector(char **tokens, int n_tokens);

#endif /* YAKS_CONNECTOR */