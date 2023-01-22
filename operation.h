#include "linked_list.h"
#include <time.h>
#define trials 1

typedef int (*operation)(int value, struct node **head);
void randomize(operation *arr, int n);
operation *start_program();

double get_avg(clock_t *time_list);
double get_std(clock_t *time_list, double mean);