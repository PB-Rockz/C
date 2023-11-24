#include <stdio.h>

void printDigit(int digit)
{
    switch (digit)
    {
    case 1:
        printf("One ");
        break;
    case 2:
        printf("Two ");
        break;
    case 3:
        printf("Three ");
        break;
    case 4:
        printf("Four ");
        break;
    case 5:
        printf("Five ");
        break;
    case 6:
        printf("Six ");
        break;
    case 7:
        printf("Seven ");
        break;
    case 8:
        printf("Eight ");
        break;
    case 9:
        printf("Nine ");
        break;
    default:
        break;
    }
}

void printTwoDigits(int number)
{
    if (number < 10)
    {
        printDigit(number);
    }
    else if (number >= 10 && number <= 19)
    {
        switch (number)
        {
        case 10:
            printf("Ten ");
            break;
        case 11:
            printf("Eleven ");
            break;
        case 12:
            printf("Twelve ");
            break;
        case 13:
            printf("Thirteen ");
            break;
        case 14:
            printf("Fourteen ");
            break;
        case 15:
            printf("Fifteen ");
            break;
        case 16:
            printf("Sixteen ");
            break;
        case 17:
            printf("Seventeen ");
            break;
        case 18:
            printf("Eighteen ");
            break;
        case 19:
            printf("Nineteen ");
            break;
        default:
            break;
        }
    }
    else
    {
        int tens = number / 10;
        int ones = number % 10;
        switch (tens)
        {
        case 2:
            printf("Twenty ");
            break;
        case 3:
            printf("Thirty ");
            break;
        case 4:
            printf("Forty ");
            break;
        case 5:
            printf("Fifty ");
            break;
        case 6:
            printf("Sixty ");
            break;
        case 7:
            printf("Seventy ");
            break;
        case 8:
            printf("Eighty ");
            break;
        case 9:
            printf("Ninety ");
            break;
        default:
            break;
        }
        printDigit(ones);
    }
}

int main()
{
    int number;
    printf("Enter an integer (0-9999): ");
    scanf("%d", &number);

    if (number < 0 || number > 9999)
    {
        printf("Number out of range. Please enter a number between 0 and 9999.\n");
        return 1;
    }

    if (number == 0)
    {
        printf("Zero\n");
        return 0;
    }

    int thousands = number / 1000;
    int hundreds = (number % 1000) / 100;
    int tensAndOnes = number % 100;

    if (thousands > 0)
    {
        printDigit(thousands);
        printf("Thousand ");
    }

    if (hundreds > 0)
    {
        printDigit(hundreds);
        printf("Hundred ");
    }

    if (tensAndOnes > 0)
    {
        printTwoDigits(tensAndOnes);
    }

    printf("\n");

    return 0;
}
