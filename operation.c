#include "operation.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static operation ops[M];

operation *get_operation_list( float m_member,float m_insert,float m_delete){
    for (size_t i = 0; i < m_member; i++)
    {
       ops[i]=&Member;
    }
    for (size_t i = m_member; i < m_member+m_insert; i++)
    {
       ops[i]=&Delete;
    }
    for (size_t i = m_member+m_insert; i < m_member+m_insert+m_delete; i++)
    {
       ops[i]=&Insert;
    }
   // randomize(ops,N);
    return ops;
}

void swap (operation *a, operation *b)
{
    operation t = *a;
    *a = *b;
    *b = t;
}

void randomize ( operation *arr, int n )
{
    srand ( time(NULL) );
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
         swap(&arr[i], &arr[j]);
    }
}
