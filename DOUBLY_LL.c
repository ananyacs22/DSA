#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void insert()
{
    struct node *newnode, *temp;
    int value;

    printf("Enter the value before which to insert: ");
    scanf("%d", &value);

    temp = head;
    while(temp != NULL && temp->data != value)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    newnode->prev = temp->prev;
    newnode->next = temp;

    if(temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
}

void delete()
{
    struct node *temp;
    int value;

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    while(temp != NULL && temp->data != value)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted successfully!\n");
}

void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Doubly Linked List: ");

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Create\n2. Insert to the left\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create();
                    break;

            case 2: insert();
                    break;

            case 3: delete();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);

            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

