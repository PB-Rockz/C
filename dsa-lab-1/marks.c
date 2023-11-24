#include <stdio.h>

int main() {
    float marks[5];
    float totalMarks = 0;

    printf("Enter the marks obtained in five subjects (out of 100):\n");
    for (int i = 0; i < 5; i++) {
        validator:
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);

       // Validate marks to be within the range 0 to 100
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Please enter marks between 0 and 100.\n");
            goto validator;
        }

        totalMarks += marks[i];
    }
    float percentage = totalMarks / (5 * 100) * 100;
// %.2lf displays float upto 2 decimal places
    printf("\nAggregate marks: %.2lf\n", totalMarks);
    printf("Percentage marks: %.2lf%%\n", percentage);

    return 0;
}
