#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NUM_THREADS	5

void *holaMundo(void *threadid);

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   void *status;
   for(t=0;t<NUM_THREADS;t++){
     printf("Hilo principal: creando hilo %ld\n", t);
     rc = pthread_create(&threads[t], NULL, holaMundo, &(void *)t);

     if (rc){
       printf("ERROR; El código regresado por funcion pthread_create() es: %d\n", rc);
       exit(-1);
       }

     // Retardo que permite ver la ejecucuión ordenada de hilos
     //sleep(4);
     //sleep(random()%2);
     //printf("\n\n");
     }	//fin bloque for

   rc = pthread_join(threads[0],&status);
   rc = pthread_join(threads[1],&status);
   rc = pthread_join(threads[2],&status);
   rc = pthread_join(threads[3],&status);
   rc = pthread_join(threads[4],&status);

   /* Last thing that main() should do */
   printf("Hilo principal: terminado\n\n");
   pthread_exit(NULL);
}

// Funcion cuya tarea es mostrar en consola un mensaje
void *holaMundo(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hilo #%ld: ¡Hola mundo! Soy el hilo #%ld\n", tid,tid);
   pthread_exit(NULL);
}