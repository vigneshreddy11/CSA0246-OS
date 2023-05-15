#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int shared_data = 0;
sem_t semaphore;

void* printDouble(void* arg) {
    int data;
    sem_wait(&semaphore);  // Wait for access to shared memory
    data = shared_data;
    sem_post(&semaphore);  // Release access to shared memory
    printf("Double of the shared data: %d\n", data * 2);
    pthread_exit(NULL);
}

void* printFiveTimes(void* arg) {
    int data;
    sem_wait(&semaphore);  // Wait for access to shared memory
    data = shared_data;
    sem_post(&semaphore);  // Release access to shared memory
    printf("Five times the shared data: %d\n", data * 5);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int input;

    // Initialize semaphore
    sem_init(&semaphore, 0, 1);

    // Get input from user
    printf("Enter an integer: ");
    scanf("%d", &input);

    // Update shared data
    sem_wait(&semaphore);  // Wait for access to shared memory
    shared_data = input;
    sem_post(&semaphore);  // Release access to shared memory

    // Create thread 1
    if (pthread_create(&thread1, NULL, printDouble, NULL) != 0) {
        fprintf(stderr, "Failed to create thread 1.\n");
        return 1;
    }

    // Create thread 2
    if (pthread_create(&thread2, NULL, printFiveTimes, NULL) != 0) {
        fprintf(stderr, "Failed to create thread 2.\n");
        return 1;
    }

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}
