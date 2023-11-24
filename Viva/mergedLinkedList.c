#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[50];
    char dob[12];
    char section;
    struct Student *next;
} Node;

Node *createStudent(char name[], char dob[], char section)
{
    Node *newStudent = (Node *)malloc(sizeof(Node));
    strcpy(newStudent->name, name);
    strcpy(newStudent->dob, dob);
    newStudent->section = section;
    newStudent->next = NULL;
    return newStudent;
}

void insertStudent(Node **head, char name[], char dob[], char section)
{
    Node *newStudent = createStudent(name, dob, section);
    if (*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newStudent;
    }
}

Node *mergeSortedLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    Node *mergedList = NULL;
    Node *lastNode = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (strcmp(list1->name, list2->name) < 0 || (strcmp(list1->name, list2->name) == 0 && strcmp(list1->dob, list2->dob) <= 0))
        {
            if (mergedList == NULL)
            {
                mergedList = list1;
                lastNode = list1;
            }
            else
            {
                lastNode->next = list1;
                lastNode = list1;
            }
            list1 = list1->next;
        }
        else
        {
            if (mergedList == NULL)
            {
                mergedList = list2;
                lastNode = list2;
            }
            else
            {
                lastNode->next = list2;
                lastNode = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL)
    {
        lastNode->next = list1;
    }

    if (list2 != NULL)
    {
        lastNode->next = list2;
    }

    return mergedList;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("Name: %s, DOB: %s, Section: %c\n", current->name, current->dob, current->section);
        current = current->next;
    }
}

int main()
{
    Node *sectionA = NULL;
    Node *sectionB = NULL;
    Node *mergedSection = NULL;

    int n;
    printf("Enter the number of students in Section A: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char name[50];
        char dob[12];
        char section = 'A';
        printf("Enter name and DOB for student %d in Section A: ", i + 1);
        scanf("%s %s", name, dob);
        insertStudent(&sectionA, name, dob, section);
    }

    printf("Enter the number of students in Section B: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char name[50];
        char dob[12];
        char section = 'B';
        printf("Enter name and DOB for student %d in Section B: ", i + 1);
        scanf("%s %s", name, dob);
        insertStudent(&sectionB, name, dob, section);
    }

    mergedSection = mergeSortedLists(sectionA, sectionB);

    printf("\nMerged Section (Sorted by Name and DOB):\n");
    printList(mergedSection);

    return 0;
}
