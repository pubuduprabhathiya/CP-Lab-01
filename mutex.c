#include "operation.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t lock;

struct mutex_args {
  clock_t *time_list;
  operation *ops;
  int thread_id;
  int num_of_thread;
  int trial_num;
};

void *run_program(void *ptr) {
  struct mutex_args *args = (struct mutex_args *)ptr;
  struct node *head = get_linked_list();
  clock_t time = clock();

  for (int i = args->thread_id; i < M; i + args->num_of_thread) {
    pthread_mutex_lock(&lock);
    args->ops[i](get_random(), &head);
    pthread_mutex_unlock(&lock);
  }

  args->time_list[args->trial_num] = clock() - time;
  free_all(head);
  return EXIT_SUCCESS;
}

int main() {
  int numThreads = 4;
  clock_t time_list[trials];
  operation *ops = start_program();

  

  for (int t = 0; t < trials; t++) {
    pthread_t *threadHandles;
    pthread_mutex_init(&lock, NULL);

    threadHandles = malloc(numThreads * sizeof(pthread_t));

    struct mutex_args mutex_args;
    mutex_args.num_of_thread = numThreads;
    mutex_args.ops = ops;
    mutex_args.time_list = time_list;
    mutex_args.trial_num = t;
    for (int th = 0; th < numThreads; th++) {
      pthread_create(&threadHandles[th], NULL, run_program,
                     (void *)&mutex_args);
    }

    for (int thr = 0; thr < numThreads; ++thr) {
      pthread_join(threadHandles[thr], NULL);
    }
    free(threadHandles);
    pthread_mutex_destroy(&lock);
  }
  double avg = get_avg(time_list);
  double std = get_std(time_list, avg);
  printf("Average:- %e, Std:- %e \n", avg, std);
  return 0;
}