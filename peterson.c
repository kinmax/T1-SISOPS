#include "peterson.h"

void initialize_peterson(int processes)
{
    procs = processes;
    flag = (int *) malloc(processes * sizeof(int));
    turn = (int *) malloc(processes * sizeof(int));
}

void lock_peterson(int p)
{
    int i, j, counter = 0;
    for(i = 0; i < procs; i++)
    {
        flag[p] = i;
        turn[i] = p;
        for(j = 0; j < procs; j++)
        {
            if(j != p && flag[j] < i)
            {
                counter++;
            }
        }
        while(!(counter == procs-1 || turn[i] != p))
        {
            
        }
    }
}

void unlock_peterson(int p)
{
    flag[p] = -1;
}
