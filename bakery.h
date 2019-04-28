#ifndef _bakery_h_
#define _bakery_h_

#include <stdlib.h>

int procs;
int *choosing;
int *number;

void initialize_bakery(int processes);
void lock_bakery(int p);
void unlock_bakery(int p);

#endif
