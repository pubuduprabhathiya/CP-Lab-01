struct node {
    struct node *next;
    int value;
};

int Delete(int value, struct node *head);
int Member(int value, struct node *head);
int Insert(int value, struct node **head);