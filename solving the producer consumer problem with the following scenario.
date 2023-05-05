#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];  // shared buffer
int in = 0;  // index of the next free position in buffer
int out = 0;  // index of the next item to be consumed from buffer
int count = 0;  // number of items in buffer

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // mutex to protect buffer
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER;  // condition variable for buffer not full
pthread_cond_t buffer_not_empty = PTHREAD_COND_INITIALIZER;  // condition variable for buffer not empty

void *producer(void *arg) {
    int i;
    for (i = 0; i < 4; i++) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            printf("Buffer is full. Producer is waiting...\n");
            pthread_cond_wait(&buffer_not_full, &mutex);
        }
        buffer[in] = i;
        printf("Produced item %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;
        count++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&buffer_not_empty);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item, i;
    for (i = 0; i < 1; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            printf("Buffer is empty. Consumer is waiting...\n");
            pthread_cond_wait(&buffer_not_empty, &mutex);
        }
        item = buffer[out];
        printf("Consumed item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        count--;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&buffer_not_full);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}
