/*
  The file is simply used for playing with rax functions via gdb without
  running the entire redis server.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <assert.h>
#include <errno.h>

#include "rax.h"
#include "rc4rand.h"


void insertSampleNodes(rax *rax) {
    raxInsert(rax, (unsigned char *)"foo", 3, NULL, NULL);
    raxInsert(rax, (unsigned char *)"foobar", 6, NULL, NULL);
    raxInsert(rax, (unsigned char *)"footer", 6, NULL, NULL);
    raxInsert(rax, (unsigned char *)"footnote", 8, NULL, NULL);
    raxInsert(rax, (unsigned char *)"alice", 5, NULL, NULL);
}


int main(void) {
    rax *rax = raxNew();

    raxShow(rax);
    insertSampleNodes(rax);
    raxShow(rax);

    raxFree(rax);

    return 0;
}