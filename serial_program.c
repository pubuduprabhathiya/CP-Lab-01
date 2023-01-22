#include "operation.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define trials 97

float get_avg(clock_t *time_list) {
  double sum = 0;
  for (size_t i = 0; i < trials; i++) {
    sum += (double)time_list[i] / (CLOCKS_PER_SEC);
  }
  return sum / trials;
}
float get_std(clock_t *time_list, double mean) {
  double std = 0;
  for (size_t i = 0; i < trials; i++) {
    std += pow((double)time_list[i] / CLOCKS_PER_SEC - mean, 2);
  }
  return sqrt(std / trials);
}

int main() {

  int case_num = 1;
  int m_member, m_insert, m_delete;
  printf("Enter case nuber: ");
  scanf("%d", &case_num);

  if (case_num == 1)
    m_member = M * 0.99, m_insert = M * 0.005, m_delete = M * 0.005;
  else if (case_num == 2)
    m_member = M * 0.90, m_insert = M * 0.05, m_delete = M * 0.05;
  else if (case_num == 3)
    m_member = M * 0.50, m_insert = M * 0.25, m_delete = M * 0.25;
  printf("Start Program with m_member:- %i, m_insert:- %i, m_delete:- %i\n",
         m_member, m_insert, m_delete);
  operation *ops = get_operation_list(m_member, m_insert, m_delete);
  clock_t time_list[trials];

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
