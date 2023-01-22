
#define N 1000
#define M 10000
#define MAX_VALUE (1 << 16) - 1

struct node {
  struct node *next;
  int value;
};

int get_random();
int Delete(int value, struct node **head);
int Member(int value, struct node **head);
int Insert(int value, struct node **head);
void free_all(struct node *head);
struct node *get_linked_list();