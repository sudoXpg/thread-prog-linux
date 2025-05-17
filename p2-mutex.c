#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

// A mutex (Mutual Exclusion) ensures that only one thread at a time can execute the critical section of code that modifies shared data.
//
//  blocks other threads from entering the critical section

void *func();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter=0;


int main(void){
    pthread_t thread1, thread2;
    if(pthread_create(&thread1, NULL, func, NULL)){
        printf("[error] creating thread 1\n");
    }
    if(pthread_create(&thread2, NULL, func, NULL)){
        printf("[error] creating thread 2\n");
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void *func(){
    printf("Thread number %ld\n", pthread_self());
    pthread_mutex_lock(&mutex1);
    counter++;
    printf("Counter value: %d\n",counter);
    pthread_mutex_unlock( &mutex1 );
}