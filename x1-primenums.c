#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define THREAD_COUNT 1024
#define NUMS_PER_THREAD 500

int count=0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *prime_check_for_10k(void *initial_value);

int main(void){

    int nums[THREAD_COUNT];
    
    for(int i=0;i<THREAD_COUNT;i++){
        nums[i] = i*NUMS_PER_THREAD;
    }

    pthread_t threads[THREAD_COUNT];
    
    for(int i=0;i<THREAD_COUNT;i++){
        if(pthread_create(&threads[i], NULL, prime_check_for_10k, (void *)&nums[i]));
    }

    for(int i=0;i<THREAD_COUNT;i++){
        pthread_join(threads[i], NULL);
    }

    printf("Number of primes from 0 to %d : %d\n", (THREAD_COUNT*NUMS_PER_THREAD), count);

}

int prime_check(int n){
    if (n <= 1) return -1;
    if (n == 2) return 0;
    if (n % 2 == 0) return -1;
    for (int i = 3; i*i <= n; i += 2){
        if (n % i == 0) return -1;
    }
    return 0;
}

void *prime_check_for_10k(void *initial_value){
    int n = *((int *)initial_value);
    for(int i=n;i<n+NUMS_PER_THREAD;i++){
        if(prime_check(i)!=-1){
            pthread_mutex_lock(&mutex1);
            count++;
            pthread_mutex_unlock( &mutex1 );
        }
    }
}

