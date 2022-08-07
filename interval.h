#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// interval structure
struct interval_object
{
    int delay;
    void (*function)();
};

// public accessible
typedef struct interval_object interval_object;

// thread args
typedef struct {
    interval_object *obj;
} thread_args;

// implicit declarations
void *interval_loop(void *__args);
void *timeout_delay(void *__args);

/**
 * @brief Set an interval's repeating timer
 * 
 * @param interval - the interval
 */
void set_interval(interval_object *interval)
{
    // get args
    thread_args args = { interval };

    // create thread
    pthread_t thread;
    pthread_create(&thread, NULL, interval_loop, &args);
    pthread_join(thread, NULL);
}

/**
 * @brief Run interval loop
 * 
 * @param __args - thread args
 * @return void* 
 */
void *interval_loop(void *__args)
{
    // get args
    thread_args *args = (thread_args*) __args;

    // loop
    while (1)
    {
        // run function
        args->obj->function();

        // delay
        usleep(args->obj->delay * 1000);
    }
}

/**
 * @brief Set a timeout's delay
 * 
 * @param timeout - the timeout
 */
void set_timeout(interval_object *timeout)
{
    // get args
    thread_args args = { timeout };

    // create thread
    pthread_t thread;
    pthread_create(&thread, NULL, timeout_delay, &args);
    pthread_join(thread, NULL);
}

/**
 * @brief Run timeout delay
 * 
 * @param __args - thread args
 * @return void* 
 */
void *timeout_delay(void *__args)
{
    // get args
    thread_args *args = (thread_args*) __args;

    // run delay
    usleep(args->obj->delay * 1000);

    // run function
    args->obj->function();
}