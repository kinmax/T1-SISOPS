#include "bakery.h"

void initialize_bakery(int n_locks, int *processes)
{
    int i, j;
    procs = (int *) malloc(n_locks * sizeof(int));
    choosing = (int *) malloc(n_locks * sizeof(int));
    number = (int *) malloc(n_locks * sizeof(int));
    for(i = 0; i < n_locks; i++)
    {
        choosing[i] = (int *) malloc(processes[i] * sizeof(int));
        number[i] = (int *) malloc(processes[i] * sizeof(int));
        for(j = 0; j < processes[i]; j++)
        {
            choosing[i][j] = 0;
            number[i][j] = 0;
        }
    }
}

void lock(int lock_id, int p)
{
    int n_procs = procs[lock_id];
    int max, i;
    max = -1;
    choosing[lock_id][p] = 1;
    for(i = 0; i <= n_procs-1; i++)
    {
        if(number[lock_id][i] > max)
        {
            max = number[lock_id][i];
        }
    }
    number[lock_id][p] = max + 1;
    choosing[lock_id][p] = 0;
    for(i = 0; i < n_procs-1; i++)
    {
        while(choosing[lock_id][i] == 1)
        {

        }

        while(number[lock_id][i] != 0 && ((number[lock_id][i] < number[lock_id][p]) || ((number[lock_id][i] == number[lock_id][p]) && (i < p))))
        {

        }
    }
}

void unlock(int lock_id, int p)
{
    number[lock_id][p] = 0;
}
