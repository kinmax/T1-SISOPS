/*
KIN MAX PIAMOLINI GUSMÃO
MARCELO DRUMM

Foi utilizado o algoritmo bakery ao invés do algoritmo de Peterson pois, segundo o livro Operating System Concepts,
de Avi Silberschatz e Peter Galvin, 4ª edição, esse é o algoritmo recomendado para exclusão mútua por busy waiting para n processos
*/

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
