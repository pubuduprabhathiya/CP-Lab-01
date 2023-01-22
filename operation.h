#include "linked_list.h"

typedef int (*operation)(int value, struct node **head);
void randomize(operation *arr, int n);
operation *get_operation_list(float m_member, float m_insert, float m_delete);