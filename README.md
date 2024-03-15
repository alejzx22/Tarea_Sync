# Sync library for C
## Description
This library is a simple implementation of a sync library for C. It is based on the pthread library and it is intended to be used in a multi-threaded environment. The library provides a set of functions to create and manage semaphores, barriers and monitors. The library also provides a set of functions to manage the execution of threads and the synchronization of shared resources.

## Table of Contents
- [Description](#description)
- [Table of Contents](#table-of-contents)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)

## Prerequisites
To use the library, you need to have the pthread library installed on your system. The pthread library is a standard library for C that provides support for multi-threading. It is usually installed by default on most Linux distributions. If you are using a different operating system, you may need to install the library manually.
You can install the pthread library on a Debian-based system by using the following command:

```sudo apt-get install libpthread-stubs0-dev```

## Installation
To install the library, you need to clone the repository and compile the source code. The library is composed of a header file and a source file. The header file contains the function prototypes and the source file contains the implementation of the functions. To compile the source code, you need to use the following command:

```gcc -c sync.c -o sync.o```

This command will generate an object file called sync.o. You can then use this object file to link your program with the library.

## Usage
To use the library, you need to include the header file in your program and link your program with the object file. You can then use the functions provided by the library to create and manage semaphores, barriers, and monitors.

### Functions
`void sem_init(semaphore *sem, int count)`
This function initializes a semaphore with a given count. It also initializes the mutex and condition variables associated with the semaphore.
- Usage: 
````C
semaphore sem;
sem_init(&sem, 1);
````

`void sem_wait(semaphore *sem)`
This function decrements the count of a semaphore. If the count is zero, the function blocks the calling thread until the count becomes greater than zero.
- Usage: 
````C
semaphore sem;
sem_init(&sem, 1);
sem_wait(&sem);
````

`void sem_notify(semaphore *sem)`
This function increments the count of a semaphore. If there are any threads waiting on the semaphore, the function wakes up one of the waiting threads.
- Usage: 
````C
semaphore sem;
sem_init(&sem, 1);
sem_wait(&sem);
sem_notify(&sem);
````

`void barrier_init(barrier *bar, int count)`
This function initializes a barrier with a given count. It also initializes the mutex and condition variables associated with the barrier.
- Usage: 
````C
barrier bar;
barrier_init(&bar, 3);
````

`void barrier_wait(barrier *bar)`
This function blocks the calling thread until the count of the barrier becomes zero. When the count becomes zero, the function wakes up all the waiting threads.
- Usage: 
````C
barrier bar;
barrier_init(&bar, 3);
barrier_wait(&bar);
````

`void monitor_init(monitor_t *mon, int count)`
This function initializes a monitor with a given count. It also initializes the mutex and condition variables associated with the monitor.
- Usage: 
````C
monitor_t mon;
monitor_init(&mon, 1);
````

`void monitor_wait(monitor_t *mon)`
This function blocks the calling thread until the count of the monitor becomes zero. When the count becomes zero, the function wakes up all the waiting threads.
- Usage: 
````C
monitor_t mon;
monitor_init(&mon, 1);
monitor_wait(&mon);
````

`void monitor_notify(monitor_t *mon)`
This function increments the count of a monitor. If there are any threads waiting on the monitor, the function wakes up one of the waiting threads.
- Usage: 
````C
monitor_t mon;
monitor_init(&mon, 1);
monitor_wait(&mon);
monitor_notify(&mon);
````


## Example
The library provides a simple example program that demonstrates how to use the functions provided by the library. 
To compile the example program, you can use the following command:

```gcc test.c sync.o -o test```

This command will generate an executable file called test. You can then run the example program by using the following command:
```./test```

## Authors
- Alejandro Alfaro Rojas
- Bianka Mora Meléndez
- Bryan Sandí Quirós
