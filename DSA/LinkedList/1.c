#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node in the linked list
struct Student
{
    int roll;
    char name[25];
    int age;
    struct Student *next;
};
typedef struct Student node;

node *createStudent()
{
    int k, n;
    node *p, *head;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        if (k == 0)
        {
            head = (node *)malloc(sizeof(node));
            p = head;
        }
        else
        {
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
        }
        printf("Roll: ");
        scanf("%d", &p->roll);
        printf("Name: ");
        scanf("%s", &p->name);
        printf("Age: ");
        scanf("%d", &p->age);
        printf("\n");
    }
    p->next = NULL;
    return (head);
}

void printStudents(node *head)
{
    node *current = head;

    printf("Student Records:\n");
    int count = 1;
    while (current != NULL)
    {
        printf("%d Node is: \n", count++);
        printf("Roll: %d, Name: %s, Age: %d\n", current->roll, current->name, current->age);
        current = current->next;
    }
}
void delStudent(node **head)
{
    int rno;
    node *p, *q;
    printf("\nRoll No to be deleted: ");
    scanf("%d", &rno);
    p = *head;
    if (p->roll == rno)
    {
        *head = p->next;
        free(p);
    }
    else
    {
        while ((p != NULL) && (p->roll != rno))
        {
            q = p;
            p = p->next;
        }
        if (p == NULL)
        {
            printf("\nRollNo not found :: Deletion Failed  \n");
        }
        else if (p->roll == rno)
        {
            q->next = p->next;
            free(p);
        }
    }
}

void addStudent(node **head)
{
    int k = 0, rno;
    node *p, *q, *new;
    new = (node *)malloc(sizeof(node));
    printf("\nData to be inserted:\n");
    printf("Roll: ");
    scanf("%d", &new->roll);
    printf("Name: ");
    scanf("%s", new->name);
    printf("Age: ");
    scanf("%d", &new->age);
    printf("\nInsert Roll No before Roll (-ve for end): ");
    scanf("%d", &rno);
    p = *head;
    if (p->roll == rno)
    {
        new->next = p;
        *head = new;
    }
    else
    {
        while ((p != NULL) && (p->roll != rno))
        {
            q = p;
            p = p->next;
        }
        if (p == NULL)
        {
            q->next = new;
            new->next = NULL;
        }
        else if (p->roll == rno)
        {
            q->next = new;
            new->next = p;
        }
    }
}

int main()
{
    node *head = createStudent();
    printStudents(head);

    return 0;
}
