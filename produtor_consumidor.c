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
        //lock_bakery(i);
        sem_wait(&mutex);
        lock_bakery(i);
        sem_post(&mutex);
        sem_wait(&empty);
        
        buffer++;
        printf("(P) Thread %ld produziu. Buffer = %d\n", i, buffer);
       
        sem_post(&full);
        sem_wait(&mutex);
        unlock_bakery(i);
        sem_post(&mutex);
        //unlock_bakery(i);
        
    }
}

void consumidor(void *arg)
{
    long int i;
    i = (long int)arg;
    while(1)
    {
        //lock_bakery(PRODUTORES+i);
        sem_wait(&mutex);
        lock_bakery(PRODUTORES+i);
        sem_post(&mutex); 
        sem_wait(&full);
               
        buffer--;
        printf("(C) Thread %ld consumiu. Buffer = %d\n", i, buffer);
        
        sem_post(&empty);
        sem_wait(&mutex);
        unlock_bakery(PRODUTORES+i);
        sem_post(&mutex);
        //unlock_bakery(PRODUTORES+i);
        
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
		pthread_create(&consumers[i], NULL, produtor, (void *)i);

	for(i = 0; i < PRODUTORES; i++)
		pthread_create(&producers[i], NULL, consumidor, (void *)i);

	pthread_exit(NULL);	
	return(0);
}
