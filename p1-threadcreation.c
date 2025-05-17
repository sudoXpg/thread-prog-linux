#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>


void *print_msg_fxn(void *msg);

int main(void){
    pthread_t thread1, thread2;
    char *msg1 = "Thread 1";
    char *msg2 = "Thread 2";

    int ret1 = pthread_create(&thread1, NULL, print_msg_fxn, (void *) msg1);
    int ret2 = pthread_create(&thread1, NULL, print_msg_fxn, (void *) msg2);

    // The pthread_join() function waits for the thread specified by thread to terminate.  If that thread has already terminated, then pthread_join() returns immediately.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 returns: %d\n",ret1);
    printf("Thread 2 returns: %d\n",ret2);
    
    return 0;
}

void *print_msg_fxn( void *ptr ){
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);
}