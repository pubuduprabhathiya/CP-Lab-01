#include "operation.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pthread_mutex_rwlock.h"


int main() {

  for (int case_num = 1; case_num <= 3; case_num++) {

    clock_t time_list[trials];
    operation *ops = start_program(case_num);
    for (int t = 0; t < trials; t++) {
      struct node *head = get_linked_list();
      clock_t time = clock();
      for (int i = 0; i < M; i++) {
        ops[i](get_random(), &head);
      }
      time_list[t] = clock() - time;
      free_all(head);
    }
    double avg = get_avg(time_list);
    double std = get_std(time_list, avg);
    printf("Average:- %f, Std:- %f \n", avg, std);

    for (int n = 1; n <= 8; n=n << 1) {
      run_mutex(case_num, n);
      run_rwlock(case_num, n);
    }
  }
}
