/*
KIN MAX PIAMOLINI GUSMÃO
MARCELO DRUMM
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "bakery.h"

#define PRODUTORES 2
#define CONSUMIDORES 4

sem_t empty, full;

sem_t mutex;

int buffer;

void produtor(void *arg)
{
    long int i;
    i = (long int)arg;
    while(1)
    {
        sem_wait(&empty);
        lock_bakery(i);
        buffer++;
        printf("(P) Thread %ld produziu. Buffer = %d\n", i, buffer);
        unlock_bakery(i); 
        sem_post(&full); 
    }
}

void consumidor(void *arg)
{
    long int i;
    i = (long int)arg;
    while(1)
    {
        sem_wait(&full);
        lock_bakery(PRODUTORES+i);
        buffer--;
        printf("(C) Thread %ld consumiu. Buffer = %d\n", i, buffer);
        unlock_bakery(PRODUTORES+i);
        sem_post(&empty);
    }
}

int main(void)
{
    long int i;
    buffer = 0;
	pthread_t producers[PRODUTORES], consumers[CONSUMIDORES];
	
	initialize_bakery(PRODUTORES + CONSUMIDORES);

    sem_init(&mutex, 0, 1);

	sem_init(&full, 0, 0);
	sem_init(&empty, 0, 10);

	for(i = 0; i < CONSUMIDORES; i++)
		pthread_create(&consumers[i], NULL, consumidor, (void *)i);

	for(i = 0; i < PRODUTORES; i++)
		pthread_create(&producers[i], NULL, produtor, (void *)i);

	pthread_exit(NULL);	
	return(0);
}
