#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define a structure to represent the stack
struct Stack
{
    int data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push %d.\n", value);
    }
    else
    {
        stack->data[++(stack->top)] = value;
        printf("%d pushed to the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Signifies an error or empty stack
    }
    else
    {
        int value = stack->data[stack->top];
        (stack->top)--;
        return value;
    }
}

// Function to get the top element of the stack without popping it
int top(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1; // Signifies an error or empty stack
    }
    else
    {
        return stack->data[stack->top];
    }
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top of the stack: %d\n", top(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    if (isEmpty(&stack))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }

    return 0;
}
