#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int get_random(){
    return rand()%MAX_VALUE;
}

int Delete(int value, struct node *head){
    struct node *curr=head;
    if (curr == NULL)
    {
        return 0;
    }
    
    if(curr->value==value){
        curr->next=curr->next->next;
        free(curr);
        return 1;
    }
    if(curr->next !=NULL){
        struct node *next=curr->next;
        while (next!=NULL)
        {
            if(next->value==value){
                curr->next=next->next;
                free(next); 
                return 1;
            }
            curr=next;
            next=next->next;
        }
    }
    return 0;
}


int Member(int value, struct node *head){
    struct node *curr = head;
    
    while (curr != NULL && curr->value < value){
        curr = curr->next;
    }

    if (curr == NULL || curr->value > value){
        return 0;
    }else{
        return 1;
    }
}

int Insert(int value, struct node **head){
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *temp;

    while(curr != NULL && curr->value < value){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL || curr->value > value){
        temp = malloc(sizeof(struct node));
        temp->value = value;
        temp->next = curr;
        if(prev == NULL)
            *head = temp;
        else    
            prev->next = temp;
        return 1;
    }else{
        return 0;
    }
}

struct node *get_linked_list(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->value=get_random();

    int i=0;
    while (i<N)
    {
        i+=Insert(get_random(),&head);
    }
    return head;
}