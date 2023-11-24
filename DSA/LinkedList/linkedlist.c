#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node in the linked list
struct Student
{
    int roll;
    char name[25];
    int age;
    struct Student *link;
};

// Function to create a new student node with the given data
struct Student *createStudent(int roll, const char *name, int age)
{
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newStudent->roll = roll;
    strncpy(newStudent->name, name, sizeof(newStudent->name));
    newStudent->age = age;
    newStudent->link = NULL;
    return newStudent;
}

// Function to insert a student at the end of the linked list
void insertStudent(struct Student **head, int roll, const char *name, int age)
{
    struct Student *newStudent = createStudent(roll, name, age);

    if (*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        struct Student *current = *head;
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = newStudent;
    }
}

// Function to print the student records in the linked list
void printStudents(struct Student *head)
{
    struct Student *current = head;

    printf("Student Records:\n");
    while (current != NULL)
    {
        printf("Roll: %d, Name: %s, Age: %d\n", current->roll, current->name, current->age);
        current = current->link;
    }
}

// Function to deallocate memory used by the linked list
void freeStudents(struct Student *head)
{
    struct Student *current = head;
    while (current != NULL)
    {
        struct Student *temp = current;
        current = current->link;
        free(temp);
    }
}

int main()
{
    int numUsers;
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    struct Student *head = NULL;

    for (int i = 0; i < numUsers; i++)
    {
        int roll, age;
        char name[25];
        printf("Enter student %d details:\n", i + 1);
        printf("Roll: ");
        scanf("%d", &roll);
        printf("Name: ");
        scanf("%s", name);
        printf("Age: ");
        scanf("%d", &age);

        insertStudent(&head, roll, name, age);
    }

    // Print the student records
    printStudents(head);

    // Deallocate memory
    freeStudents(head);

    return 0;
}
