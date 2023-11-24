#include <stdio.h>

int main() {
    float d_in_km;

    printf("Enter the distance between two cities (in km): ");
    scanf("%f", &d_in_km);

    float d_in_m = d_in_km * 1000;
    float d_in_f = d_in_km * 3280.84;
    float d_in_in = d_in_km * 39370.1;
    float d_in_cm = d_in_km * 100000;
// %.2lf displays float upto 2 decimal places
    printf("Distance in meters: %.2lf m\n", d_in_m);
    printf("Distance in feet: %.2lf ft\n", d_in_f);
    printf("Distance in inches: %.2lf in\n", d_in_in);
    printf("Distance in centimeters: %.2lf cm\n", d_in_cm);

    return 0;
}
