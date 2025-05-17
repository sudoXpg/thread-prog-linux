#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define NUM_THREADS 16
#define rad_multiplier 0.1

void *sin_cos_calc(void *rad);

int main(void){
    pthread_t threads[NUM_THREADS];

    for(int i=0;i<NUM_THREADS;i++){
        int *arg = malloc(sizeof(int));  // separate memory for each
        *arg = i;
        if(pthread_create(&threads[i], NULL, sin_cos_calc, (void *)arg)){
            fprintf(stderr, "Error creating thread %d\n", i);
            free(arg);
        }
    }

    for(int i=0;i<NUM_THREADS;i++){
        pthread_join(threads[i], NULL);
    }

}

void *sin_cos_calc(void *rad) {
    float x =  rad_multiplier * (float)(*((int *)rad)); 
    free(rad);
    float x2 = x * x;
    float x3 = x2 * x;
    float x4 = x2 * x2;
    float x5 = x3 * x2;
    float x6 = x4 * x2;
    float x7 = x5 * x2;

    float sinx = x - x3 / 6.0f + x5 / 120.0f - x7 / 5040.0f;
    float cosx = 1.0f - x2 / 2.0f + x4 / 24.0f - x6 / 720.0f;

    printf("Angle: %f, sin(x) ≈ %.6f, cos(x) ≈ %.6f\n", x, sinx, cosx);

    return NULL;
}
