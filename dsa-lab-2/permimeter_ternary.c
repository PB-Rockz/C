#include <stdio.h>

int main() {
    float length1, breadth1, length2, breadth2, length3, breadth3;
    float perimeter1, perimeter2, perimeter3;

    printf("Enter the length and breadth of Rectangle 1: ");
    scanf("%f %f", &length1, &breadth1);

    printf("Enter the length and breadth of Rectangle 2: ");
    scanf("%f %f", &length2, &breadth2);

    printf("Enter the length and breadth of Rectangle 3: ");
    scanf("%f %f", &length3, &breadth3);

    perimeter1 = 2 * (length1 + breadth1);
    perimeter2 = 2 * (length2 + breadth2);
    perimeter3 = 2 * (length3 + breadth3);

    float maxPerimeter = (perimeter1 > perimeter2) ?
                        ((perimeter1 > perimeter3) ? perimeter1 : perimeter3) :
                        ((perimeter2 > perimeter3) ? perimeter2 : perimeter3);

    if (maxPerimeter == perimeter1) {
        printf("Rectangle 1 has the highest perimeter.\n");
    } else if (maxPerimeter == perimeter2) {
        printf("Rectangle 2 has the highest perimeter.\n");
    } else {
        printf("Rectangle 3 has the highest perimeter.\n");
    }

    return 0;
}
