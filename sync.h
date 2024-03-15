#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
} semaphore;

void sem_init(semaphore *sem, int count);
void sem_wait(semaphore *sem);
void sem_notify(semaphore *sem);

// Barrier
typedef struct {
    int count;
    int limit;
    pthread_mutex_t mutex;
    pthread_cond_t all_reached;
    pthread_cond_t all_exited;
} barrier;

void barrier_init(barrier *barrier, int limit);
void barrier_wait(barrier *barrier);

// Monitor
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
} monitor_t;

void monitor_init(monitor_t *mon, int count);
void monitor_wait(monitor_t *mon);
void monitor_notify(monitor_t *mon);
