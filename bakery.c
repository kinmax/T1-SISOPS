/*
KIN MAX PIAMOLINI GUSMÃO
MARCELO DRUMM

Foi utilizado o algoritmo bakery ao invés do algoritmo de Peterson pois, segundo o livro Operating System Concepts,
de Avi Silberschatz e Peter Galvin, 4ª edição, esse é o algoritmo recomendado para exclusão mútua por busy waiting para n processos
*/

#include <stdlib.h>
#include <stdio.h>
#include "bakery.h"

void initialize_bakery(int processes)
{
    int i;
    procs = processes;
    choosing = (int *) malloc(processes * sizeof(int));
    number = (int *) malloc(processes * sizeof(int));
    
    for(i = 0; i < processes; i++)
    {
        choosing[i] = 0;
        number[i] = 0;
    }
}

void lock_bakery(int p)
{
    int max, i;
    max = number[0];
    choosing[p] = 1;
    for(i = 0; i < procs; i++)
    {
        if(number[i] > max)
        {
            max = number[i];
        }
    }
    number[p] = max + 1;
    choosing[p] = 0;
    for(i = 0; i < procs; i++)
    {
        while(choosing[i] == 1)
        {

        }

        while(number[i] != 0 && ((number[i] < number[p]) || ((number[i] == number[p]) && (i < p))))
        {

        }
    }
}

void unlock_bakery(int p)
{
    number[p] = 0;
}
