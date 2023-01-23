#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int get_random() { return rand() % MAX_VALUE; }

int Delete(int value, struct node **head) {
  struct node *curr = *head;
  struct node *prev = NULL;
  while (curr != NULL && curr->value < value) {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL || curr->value > value) {
    return 0;
  } else {
    if (prev == NULL) {
      *head = curr->next;
      free(curr);
    } else {
      prev->next = curr->next;
      free(curr);
    }

    return 1;
  }
}

int Member(int value, struct node **head) {
  struct node *curr = *head;

  while (curr != NULL && curr->value < value) {
    curr = curr->next;
  }

  if (curr == NULL || curr->value > value) {
    return 0;
  } else {
    return 1;
  }
}

int Insert(int value, struct node **head) {
  struct node *curr = *head;
  struct node *prev = NULL;
  while (curr != NULL && curr->value < value) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL || curr->value > value) {

    if (prev == NULL) {
      *head = (struct node *)malloc(sizeof(struct node));
      (*head)->next = NULL;
      (*head)->value = value;
    } else {
      prev->next = (struct node *)malloc(sizeof(struct node));
      prev->next->value = value;
      prev->next->next = curr;
    }

    return 1;
  } else {
    return 0;
  }
}

struct node *get_linked_list() {
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->value = get_random();
  head->next = NULL;

  int i = 0;
  while (i < N) {
    i += Insert(get_random(), &head);
  }
  return head;
}

void free_all(struct node *head) {
  struct node *curr = head;
  struct node *next = NULL;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
}
