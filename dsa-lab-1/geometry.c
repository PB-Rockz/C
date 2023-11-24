#include <stdio.h>
#include <math.h>

int main() {
    float length, breadth, radius;
    float rectangleArea, rectanglePerimeter;
    float circleArea, circleCircumference;

    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);

    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &breadth);

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    rectangleArea = length * breadth;
    rectanglePerimeter = 2 * (length + breadth);

    circleArea = 3.141 * pow(radius, 2);
    circleCircumference = 2 * 3.141 * radius;
// %.2lf displays float upto 2 decimal places

    printf("\nRectangle:\n");
    printf("Area: %.2lf\n", rectangleArea);
    printf("Perimeter: %.2lf\n", rectanglePerimeter);

    printf("\nCircle:\n");
    printf("Area: %.2lf\n", circleArea);
    printf("Circumference: %.2lf\n", circleCircumference);

    return 0;
}
