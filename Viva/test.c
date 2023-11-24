#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int rollNumber;
    char name[50];
    struct Node *next;
};

void freeList(struct Node *node)
{
    struct Node *temp;
    while (node != NULL)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
}

struct Node *mergeSortedLists_roll(struct Node *a, struct Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->rollNumber < b->rollNumber)
    {
        a->next = mergeSortedLists_roll(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeSortedLists_roll(a, b->next);
        return b;
    }
}

struct Node *mergeSortedLists_name(struct Node *a, struct Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (strcmp(a->name, b->name) < 0)
    {
        a->next = mergeSortedLists_name(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeSortedLists_name(a, b->next);
        return b;
    }
}

// Function to print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("Roll Number: %d, Name: %s\n", node->rollNumber, node->name);
        node = node->next;
    }
}

int main()
{
    struct Node *batchA = NULL;
    struct Node *batchB = NULL;

    int rollNumber;
    char name[50];

    printf("Enter details for Batch A:\n");
    for (int i = 0; i < 2; ++i)
    {
        printf("Enter Roll Number for Batch A: ");
        scanf("%d", &rollNumber);
        printf("Enter Name: ");
        scanf("%s", name);

        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->rollNumber = rollNumber;
        strcpy(newNode->name, name);
        newNode->next = NULL;

        if (batchA == NULL)
        {
            batchA = newNode;
        }
        else
        {
            struct Node *temp = batchA;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("Enter details for Batch B:\n");
    for (int i = 0; i < 2; ++i)
    {
        printf("Enter Roll Number for Batch B: ");
        scanf("%d", &rollNumber);
        printf("Enter Name: ");
        scanf("%s", name);

        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->rollNumber = rollNumber;
        strcpy(newNode->name, name);
        newNode->next = NULL;

        if (batchB == NULL)
        {
            batchB = newNode;
        }
        else
        {
            struct Node *temp = batchB;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int choice;
    struct Node *mergedList = NULL;

    do
    {
        printf("Enter 1 to sort by Roll Number, 2 to sort by Name, or 3 to exit: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (mergedList != NULL)
            {
                freeList(mergedList);
            }
            mergedList = mergeSortedLists_roll(batchA, batchB);
            printf("Merged List (sorted by Roll Number):\n");
            printList(mergedList);
        }
        else if (choice == 2)
        {
            if (mergedList != NULL)
            {
                freeList(mergedList);
            }
            mergedList = mergeSortedLists_name(batchA, batchB);
            printf("Merged List (sorted by Name):\n");
            printList(mergedList);
        }
        else if (choice == 3)
            break;
        else
        {
            printf("Invalid choice. Please enter 1 or 2 or 3.\n");
        }
    } while (1);

    freeList(mergedList);

    return 0;
}
