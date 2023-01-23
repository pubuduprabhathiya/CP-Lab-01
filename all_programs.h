#include <pthread.h>

struct result {
  double avg;
  double std;
};

struct result *run_serial(int case_num);
struct result *run_mutex(int case_num, int num_of_thread);
struct result *run_rwlock(int case_num, int num_of_thread);