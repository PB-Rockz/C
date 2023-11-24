#include <stdio.h>
int main(){
    float num,res;
    printf("Enter a number to display the Table: ");
    scanf("%f",&num);
    for (int i = 1; i < 11; i++)
    {
        res = num * i;
        printf("%.2lf * %d = %.2lf\n",num,i,res);
    }
    
    return 0;
}