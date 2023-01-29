#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    usleep(thread_func_args->waitToObtainMs);
    pthread_mutex_lock(thread_func_args->mutex);
    thread_func_args->tid = pthread_self();
    usleep(thread_func_args->waitToReleaseMs);
    thread_func_args->thread_complete_success = true;
    pthread_mutex_unlock(thread_func_args->mutex);


    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    //struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    struct thread_data* data = (struct thread_data*)(malloc(sizeof(struct thread_data)));
    data->waitToObtainMs = wait_to_obtain_ms;
    data->waitToReleaseMs = wait_to_release_ms;
    data->thread = thread;
    data->mutex = mutex;
    data->tid = (pthread_t)NULL;
    data->threadInfoPtr = data;
    data->thread_complete_success = false;

    int ret = pthread_create(thread, NULL, threadfunc, (void *)data);
    if (ret != 0) 
    {
	    return false;
    }

    return true;

    
}

