#include "global.h"

void erro(char *m){
    fprintf(stderr,"linha %d: %s\n", clinha,m);
    exit(1);
}