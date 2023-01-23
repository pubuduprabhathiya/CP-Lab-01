#include "all_programs.h"
#include "graph.h"
#include "operation.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  for (int case_num = 1; case_num <= 3; case_num++) {

    double result_s[4];
    double result_m[4];
    double result_r[4];

    double s_result_s[4];
    double s_result_r[4];
    double s_result_m[4];

    struct result *result_serial = run_serial(case_num);
    result_s[0] = result_serial->avg;
    s_result_s[0] = result_serial->std;

    struct result *result_mutex;
    struct result *result_rwlock;
    int index = 0;
    for (int n = 1; n <= 8; n = n << 1) {
      result_mutex = run_mutex(case_num, n);
      result_rwlock = run_rwlock(case_num, n);
      if (index) {
        result_s[index] = 0;
        s_result_s[index] = 0;
      }
      result_m[index] = result_mutex->avg;
      result_r[index] = result_rwlock->avg;

      s_result_m[index] = result_mutex->std;
      s_result_r[index] = result_rwlock->std;

      free(result_serial);
      free(result_mutex);
      free(result_rwlock);
      index += 1;
    }
    printf("Case Number %i\n", case_num);
    printf("Serial\n");
    for (int i = 0; i < 4; i++) {
      printf("%f ,", result_s[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
      printf("%f ,", s_result_s[i]);
    }
    printf("\n");

    printf("Mutex\n");
    for (int i = 0; i < 4; i++) {
      printf("%f ,", result_m[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
      printf("%f ,", s_result_m[i]);
    }
    printf("\n");

    printf("RWLock\n");
    for (int i = 0; i < 4; i++) {
      printf("%f ,", result_r[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
      printf("%f ,", s_result_r[i]);
    }

    printf("\n\n\n");
  }
}
