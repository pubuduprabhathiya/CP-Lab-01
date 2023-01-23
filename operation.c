#include "operation.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static operation ops[M];

operation *get_operation_list(float m_member, float m_insert, float m_delete) {
  for (size_t i = 0; i < m_member; i++) {
    ops[i] = &Member;
  }
  for (size_t i = m_member; i < m_member + m_insert; i++) {
    ops[i] = &Insert;
  }
  for (size_t i = m_member + m_insert; i < m_member + m_insert + m_delete;
       i++) {
    ops[i] = &Delete;
  }
  randomize(ops, M);
  return ops;
}

void swap(operation *a, operation *b) {
  operation t = *a;
  *a = *b;
  *b = t;
}

void randomize(operation *arr, int n) {
  srand(time(NULL));
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    swap(&arr[i], &arr[j]);
  }
}

double get_avg(clock_t *time_list) {
  double sum = 0;
  for (size_t i = 0; i < trials; i++) {
    sum += (double)time_list[i] / (CLOCKS_PER_SEC);
  }
  return sum / trials;
}
double get_std(clock_t *time_list, double mean) {
  double std = 0;
  for (size_t i = 0; i < trials; i++) {
    std += pow((double)time_list[i] / CLOCKS_PER_SEC - mean, 2);
  }
  return sqrt(std / trials);
}

operation *start_program(int case_num) {
  int m_member, m_insert, m_delete;

  if (case_num == 1)
    m_member = M * 0.99, m_insert = M * 0.005, m_delete = M * 0.005;
  else if (case_num == 2)
    m_member = M * 0.90, m_insert = M * 0.05, m_delete = M * 0.05;
  else if (case_num == 3)
    m_member = M * 0.50, m_insert = M * 0.25, m_delete = M * 0.25;
  printf("Start Program with m_member:- %i, m_insert:- %i, m_delete:- %i\n",
         m_member, m_insert, m_delete);
  operation *ops = get_operation_list(m_member, m_insert, m_delete);
  return ops;
}