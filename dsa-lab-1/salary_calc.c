#include <stdio.h>
int main(){
    float basic,da,hra,gross_salary;
    jump:
    printf("Enter your Basic Salary: ");
    scanf("%f",&basic);
    // Salary Validator
    if(basic == 0){
        printf("Salary cannot be 0!!\n\n");
        goto jump;
    }
    da = basic * 0.4;
    hra = basic * 0.2;
    gross_salary = basic + da+ hra;
    // %.2lf displays float upto 2 decimal places

    printf("Your Dearness Allowance is: %.2lf",da);
    printf("\nYour House Rent Allowance is: %.2lf",hra);
    printf("\nYour Gross Salary is: %.2lf " , gross_salary);
    return 0;
}