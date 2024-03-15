
// Biblioteca con las siguientes estructuras de sincronización:
// Semáforo
// Barrera
// Monitor

// Integrantes: Bianka Mora, Alejandro Alfaro, Bryan Sandí

#include "sync.h"


// Semaphore
void sem_init(semaphore *sem, int count) {
    sem->count = count;
    pthread_mutex_init(&sem->mutex, NULL);
    pthread_cond_init(&sem->cond, NULL);
}

void sem_wait(semaphore *sem) {
    pthread_mutex_lock(&sem->mutex);
    sem->count--;
    if (sem->count == 0) {
        pthread_cond_wait(&sem->cond, &sem->mutex);
    }
    pthread_mutex_unlock(&sem->mutex);
}

void sem_notify(semaphore *sem) {
    pthread_mutex_lock(&sem->mutex);
    sem->count++;
    pthread_cond_signal(&sem->cond);
    pthread_mutex_unlock(&sem->mutex);
}

// Barrier
void barrier_init(barrier *barrier, int limit) {
    barrier->count = 0;
    barrier->limit = limit;
    pthread_mutex_init(&barrier->mutex, NULL);
    pthread_cond_init(&barrier->all_reached, NULL);
    pthread_cond_init(&barrier->all_exited, NULL);
}


void barrier_wait(barrier *barrier) {
    pthread_mutex_lock(&barrier->mutex);
    barrier->count++;
    if (barrier->count == barrier->limit) {
        barrier->count = 0;
        pthread_cond_broadcast(&barrier->all_reached);
        pthread_cond_wait(&barrier->all_exited, &barrier->mutex);
    } else {
        pthread_cond_wait(&barrier->all_reached, &barrier->mutex);
        if (barrier->count == 0) {
            pthread_cond_signal(&barrier->all_exited);
        }
    }
    pthread_mutex_unlock(&barrier->mutex);
}

// Monitor
void monitor_init(monitor_t *mon, int count) {
    mon->count = count;
    pthread_mutex_init(&mon->mutex, NULL);
    pthread_cond_init(&mon->cond, NULL);
}

void monitor_wait(monitor_t *mon) {
    pthread_mutex_lock(&mon->mutex);
    mon->count--;
    if (mon->count == 0) {
        pthread_cond_wait(&mon->cond, &mon->mutex);
    }
    pthread_mutex_unlock(&mon->mutex);
}

void monitor_notify(monitor_t *mon) {
    pthread_mutex_lock(&mon->mutex);
    mon->count++;
    pthread_cond_signal(&mon->cond);
    pthread_mutex_unlock(&mon->mutex);
}

