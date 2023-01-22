#include "operation.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

pthread_rwlock_t rw_lock;
int numThreads;

struct mutex_args {
  struct node **head;
  operation *ops;
  int thread_id;
  int num_of_thread;
};

void *run_program(void *ptr) {
  struct mutex_args *args = (struct mutex_args *)ptr;

  for (int i = args->thread_id; i < M; i = i + args->num_of_thread) {
    if (args->ops[i] == Member){
        pthread_rwlock_rdlock(&rw_lock);
        args->ops[i](get_random(), args->head);
        pthread_rwlock_unlock(&rw_lock);
    }else if(args->ops[i] == Insert){
        pthread_rwlock_wrlock(&rw_lock);
        args->ops[i](get_random(), args->head);
        pthread_rwlock_unlock(&rw_lock);
    }else if(args->ops[i] == Delete){
        pthread_rwlock_wrlock(&rw_lock);
        args->ops[i](get_random(), args->head);
        pthread_rwlock_unlock(&rw_lock);
    }
  }

  return EXIT_SUCCESS;
}

int main() {
  clock_t time_list[trials];
  operation *ops =start_program();
  printf("Enter number of treads: ");
  int err = scanf("%d", &numThreads);

  for (int t = 0; t < trials; t++) {
    pthread_t *threadHandles;
    struct node *head = get_linked_list();
    pthread_rwlock_init(&rw_lock, NULL);

    threadHandles = malloc(numThreads * sizeof(pthread_t));

    clock_t time = clock();

    for (int th = 0; th < numThreads; th++) {
      struct mutex_args *mutex_args = malloc(sizeof(struct mutex_args));
      mutex_args->head = &head;
      mutex_args->num_of_thread = numThreads;
      mutex_args->ops = ops;
      mutex_args->thread_id = th;
      pthread_create(&threadHandles[th], NULL, run_program, (void *)mutex_args);
    }
    for (int thr = 0; thr < numThreads; thr++) {
      pthread_join(threadHandles[thr], NULL);
    }

    time_list[t] = clock() - time;

    free(threadHandles);
    pthread_rwlock_destroy(&rw_lock);
    free_all(head);
  }
  double avg = get_avg(time_list);
  double std = get_std(time_list, avg);
  printf("Average:- %f, Std:- %f, threads: %d \n", avg, std, numThreads);
  return 0;
}
