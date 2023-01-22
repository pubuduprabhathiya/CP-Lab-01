#include <stdlib.h>
#include <stdio.h>
#include "operation.h"

int main(){
    
    struct node *head=get_linked_list();
    
    int case_num=1;
    float m_member, m_insert, m_delete;
    printf("Enter case nuber: ");
    scanf("%d",&case_num);

    if (case_num == 1) 
     m_member = M*0.99, m_insert = M*0.005, m_delete =M* 0.005;
    else if (case_num==2)
     m_member = M*0.90, m_insert = M*0.05, m_delete =M* 0.05;
    else if(case_num==3)
     m_member = M*0.50,m_insert = M*0.25, m_delete =M* 0.25;
    
    operation *ops= get_operation_list(m_member, m_insert, m_delete);
    for (int i=0;i<M;i++){
        ops[i](get_random(),head);
    }
}