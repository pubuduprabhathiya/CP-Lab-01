#include "operation.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  clock_t time_list[trials];
  operation *ops = start_program();

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
  return 0;
}
