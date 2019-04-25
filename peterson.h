#include <stdlib.h>

int procs;
int *turn;
int *flag;

void initialize(int processes);
void lock(int p);
void unlock(int p);
