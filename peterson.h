#include <stdlib.h>

int procs;
int *turn;
int *flag;

void initialize_peterson(int processes);
void lock_peterson(int p);
void unlock_peterson(int p);
