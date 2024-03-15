#include "sync.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void* thread1(void* arg);
void* thread2(void* arg);
void* thread3(void* arg);
void* thread4(void* arg);
void test_sem();
void test_barrier();
void test_monitor();


int main() {
    printf("Testing semaphores\n");
    test_sem();

    printf("Testing barriers\n");
    test_barrier();
    
    printf("Testing monitors\n");
    test_monitor();

    return 0;
}

void test_sem(){
    semaphore sem;
    sem_init(&sem, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, &sem);
    pthread_create(&t2, NULL, thread1, &sem);

    // Join the threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

}

void test_barrier(){
    barrier bar;
    barrier_init(&bar, 2);
    pthread_t t2, t3;
    pthread_create(&t2, NULL, thread2, &bar);
    pthread_create(&t3, NULL, thread3, &bar);

    // Join the threads
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
}

void test_monitor() {
    monitor_t mon;
    monitor_init(&mon, 2);
    pthread_t t2, t3;
    pthread_create(&t2, NULL, thread4, &mon);
    pthread_create(&t3, NULL, thread4, &mon);

    // Join the threads
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
}

void* thread1(void* arg) {
    semaphore* sem = (semaphore*) arg;
    printf("Thread 1: Waiting\n");
    sem_wait(sem);
    printf("Thread 1: Working\n");
    sem_notify(sem);
    printf("Thread 1: Done\n");
    return NULL;
}

void* thread2(void* arg) {
    barrier* bar = (barrier*) arg;
    printf("Thread 2: Working\n");
    sleep(rand() % 3);
    barrier_wait(bar);
    sleep(rand() % 3);
    printf("Thread 2: Done\n");
    return NULL;
}

void* thread3(void* arg) {
    barrier* bar = (barrier*) arg;
    printf("Thread 3: Working\n");
    sleep(rand() % 3);
    barrier_wait(bar);
    sleep(rand() % 3);
    printf("Thread 3: Done\n");
    return NULL;
}

void* thread4(void* arg) {
    monitor_t* mon = (monitor_t*) arg;
    printf("Thread 4: Working\n");
    sleep(rand() % 3);
    monitor_notify(mon);
    sleep(rand() % 3);
    printf("Thread 4: Done\n");
    return NULL;
}