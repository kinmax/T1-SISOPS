#include <stdlib.h>

int locks;
int *procs;
int **choosing;
int **number;

void initialize_bakery(int n_locks, int *processes);
void lock(int lock_id, int p);
void unlock(int lock_id, int p);