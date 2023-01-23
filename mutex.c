#include "operation.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t lock;
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
    pthread_mutex_lock(&lock);
    args->ops[i](get_random(), args->head);
    pthread_mutex_unlock(&lock);
  }

  return EXIT_SUCCESS;
}

int main() {

  int case_num = 1;
  printf("Enter case nuber: ");
  int err = scanf("%d", &case_num);

  clock_t time_list[trials];
  
  printf("Enter number of treads: ");
  err = scanf("%d", &numThreads);

  operation *ops =start_program(case_num);

  for (int t = 0; t < trials; t++) {
    pthread_t *threadHandles;
    struct node *head = get_linked_list();
    pthread_mutex_init(&lock, NULL);

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
    pthread_mutex_destroy(&lock);
    free_all(head);
  }
  double avg = get_avg(time_list);
  double std = get_std(time_list, avg);
  printf("Average:- %f, Std:- %f, threads: %d \n", avg, std, numThreads);
  return 0;
}
