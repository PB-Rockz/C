#include <stdio.h>

int main() {
    float x1, y1, x2, y2, x3, y3;

    printf("Enter the coordinates of point 1 (x y): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the coordinates of point 2 (x y): ");
    scanf("%f %f", &x2, &y2);

    printf("Enter the coordinates of point 3 (x y): ");
    scanf("%f %f", &x3, &y3);

    // Calculate slopes of the lines connecting the points
    float slope1 = (y2 - y1) / (x2 - x1);
    float slope2 = (y3 - y2) / (x3 - x2);

    if (slope1 == slope2) {
        printf("The points are collinear.\n");
    } else {
        printf("The points are not collinear.\n");
    }

    return 0;
}
