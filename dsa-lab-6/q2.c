#include <stdio.h>
#include <string.h>

// Define the structure to store customer data
struct Customer
{
    int accountNumber;
    char name[50];
    double balance;
};

int main()
{
    // Create an array to store data for a maximum of 200 customers
    struct Customer customers[200];

    int numCustomers;

    while (1)
    {
        printf("Enter the number of customers (up to 200): ");
        scanf("%d", &numCustomers);
        if (numCustomers <= 200 && numCustomers > 0)
        {
            break;
        }
        else
        {
            printf("Invalid number of customers. Please try again.\n");
        }
    }
    for (int i = 0; i < numCustomers; i++)
    {
        printf("Enter details for customer %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &customers[i].accountNumber);

        printf("Name: ");
        scanf("%s", customers[i].name);

        printf("Balance: ");
        scanf("%lf", &customers[i].balance);
    }

    printf("\nCustomer Data:\n");
    for (int i = 0; i < numCustomers; i++)
    {
        printf("Customer %d:\n", i + 1);
        printf("Account Number: %d\n", customers[i].accountNumber);
        printf("Name: %s\n", customers[i].name);
        printf("Balance: %.2lf\n", customers[i].balance);
        printf("\n");
    }

    return 0;
}
