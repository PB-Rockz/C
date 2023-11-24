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

    // Input customer data
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

    // Handle withdrawal and deposit requests
    char choice;

    do
    {
        int accountNumber, code;
        double amount;

        printf("Enter Account Number: ");
        scanf("%d", &accountNumber);

        printf("Enter Amount: ");
        scanf("%lf", &amount);

        printf("Enter Code (1 for deposit, 0 for withdrawal): ");
        scanf("%d", &code);

        int customerIndex = -1;
        for (int i = 0; i < numCustomers; i++)
        {
            if (customers[i].accountNumber == accountNumber)
            {
                customerIndex = i;
                break;
            }
        }
        if (customerIndex != -1)
        {
            if (code == 1)
            {

                customers[customerIndex].balance += amount;
                printf("Deposit successful. New balance: %.2lf\n", customers[customerIndex].balance);
            }
            else if (code == 0)
            {
                if (customers[customerIndex].balance - amount >= 100)
                {
                    customers[customerIndex].balance -= amount;
                    printf("Withdrawal successful. New balance: %.2lf\n", customers[customerIndex].balance);
                }
                else
                {
                    printf("The balance is insufficient for the specified withdrawal.\n");
                }
            }
            else
            {
                printf("Invalid code. Please enter 0 for withdrawal or 1 for deposit.\n");
            }
        }
        else
        {
            printf("Customer not found with the specified account number.\n");
        }

        printf("Want to continue?: ");
        scanf("%c", &choice);
    } while (choice == 'y' || choice == "Y");

    return 0;
}
