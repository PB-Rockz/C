#include <stdio.h>
int main(){
    int x[3];
    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter %d sides of a triangle: " , i+1);
        scanf("%d" , &x[i]);
    }
     if (x[0] == x[1] && x[1] == x[2]) {
        printf("The triangle is Equilateral.\n");
    } else if (x[0] == x[1] || x[1] == x[2] || x[0] == x[2]) {
        printf("The triangle is Isosceles.\n");
    } else {
        printf("The triangle is Scalene.\n");
    }
    return 0;
}