#include <stdio.h>
#include <stdlib.h>
struct element
{
    int info;
    struct element *next;
};
typedef struct element node;
node *start;
void create();
void display();
void insertAtBeg(int item);
void insertAtEnd(int item);
void insertAtSepeci(int item, int loc);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtSepeci(int loc);
int main()
{
    start = NULL;
    create();
    printf("Created Linked list : \n\t");
    display();

    printf("\nAdding a node at beginning : \n\t");
    insertAtBeg(35);
    display();

    printf("\nAdding a node at end : \n\t");
    insertAtEnd(95);
    display();

    printf("\nAdding a node at at specified position : \n\t");
    insertAtSepeci(85, 6);
    display();

    printf("\nDeleting the first node of the created list : \n\t");
    deleteAtBeg();
    display();

    printf("\nDeleting the end node of the created list : \n\t");
    deleteAtEnd();
    display();

    printf("\nDeleting the node at the specified position : \n\t");
    deleteAtSepeci(5);
    display();
    return 0;
}

void create()
{
    node *temp; // local pointer variable
    char choice = 'y';
    while (choice == 'y')
    {
        if (start == NULL)
        {
            start = (node *)malloc(sizeof(node));
            printf("Enter info part [int] : ");
            scanf("%d", &start->info);
            start->next = NULL;
            temp = start;
        }
        else
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
            printf("Enter next info [int] : ");
            scanf("%d", &temp->info);
            temp->next = NULL;
        }
        fflush(stdin);
        printf("Want more node - (Type 'y' or'n') : ");
        scanf("%c", &choice);
    }
}

void display()
{
    node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
}

void insertAtBeg(int item)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->info = item;
    if (start == NULL)
    {
        p->next = NULL;
    }
    else
    {
        p->next = start;
    }
    start = p;
}

void insertAtEnd(int item)
{
    node *p, *loc;
    p = (node *)malloc(sizeof(node));
    p->info = item;
    p->next = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        loc = start;
        while (loc->next != NULL)
        {
            loc = loc->next;
        }
        loc->next = p;
    }
}

void insertAtSepeci(int item, int loc)
{
    node *p, *temp;
    temp = start;
    for (int i = 1; i < loc - 1; ++i)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Less node in list.\n");
            return;
        }
    }
    p = (node *)malloc(sizeof(node));
    p->info = item;
    p->next = temp->next;
    temp->next = p;
}

void deleteAtBeg()
{
    node *p;
    if (start == NULL)
    {
        printf("Emplty List.\n");
        return;
    }
    else
    {
        p = start;
        start = start->next;
        p->next = NULL;
        // printf("Deleted node of the list = %d\n\t", p->info);
        free(p);
    }
}

void deleteAtEnd()
{
    node *p, *l;
    if (start == NULL)
    {
        printf("Empty List.\n");
        return;
    }
    if (start->next == NULL)
    {
        p = start;
        start = NULL;
        printf("Deleted node of the list = %d\n\t", p->info);
        free(p);
    }
    else
    {
        l = start;
        p = start->next;
        while (p->next != NULL)
        {
            l = p;
            p = p->next;
        }
        l->next = NULL;
        // printf("Deleted node of the list = %d\n\t", p->info);
        free(p);
    }
}

void deleteAtSepeci(int loc)
{
    node *p, *temp;
    temp = start;
    p = start->next;
    for (int i = 1; i < loc-1; i++)
    {
        temp = p;
        p = p->next;
    }
    temp->next = p->next;
    p->next = NULL;    
   // printf("Deleted node with value = %d\n", p->info);
    free(p);
}

/*

Enter info part [int] : 45
Want more node - (Type 'y' or'n') : y
Enter next info [int] : 55
Want more node - (Type 'y' or'n') : y
Enter next info [int] : 65
Want more node - (Type 'y' or'n') : y
Enter next info [int] : 75
Want more node - (Type 'y' or'n') : n
Created Linked list :
        45      55      65      75
Adding a node at beginning :
        35      45      55      65      75
Adding a node at end :
        35      45      55      65      75      95
Adding a node at at specified position :
        35      45      55      65      75      85      95
Deleting the first node of the created list :
        45      55      65      75      85      95
Deleting the end node of the created list :
        45      55      65      75      85
Deleting the node at the specified position :
        45      55      65      75
        
*/