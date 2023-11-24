#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5.0 / 9.0;
// %.2lf displays float upto 2 decimal places
    printf("Temperature in Celsius: %.2lf\n", celsius);

    return 0;
}
