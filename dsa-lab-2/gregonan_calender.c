#include <stdio.h>
int main(){
    int g_year = 2001 , input_year ;
    year_validator:
    printf("Enter the Year after 2001: ");
    scanf("%d" , &input_year);
    if(input_year < 2000){
        goto year_validator;
    }
    int difference_years;
    difference_years = input_year - g_year + 1;
    int no_of_leap_years;
    no_of_leap_years = difference_years / 4;
    int flag;
    flag = difference_years + no_of_leap_years;
    int weekday = flag % 7;
    printf("%d %d %d %d" , difference_years , no_of_leap_years , flag , weekday);
    switch (weekday)
    {
    case 1:
        printf("The weekday on 1st of Jan of %d is Monday." , input_year);
        break;
    case 2:
        printf("The weekday on 1st of Jan of %d is Tuesday." , input_year);
        break;
    case 3:
        printf("The weekday on 1st of Jan of %d is Wednesday." , input_year);
        break;
    case 4:
        printf("The weekday on 1st of Jan of %d is Thrusday." , input_year);
        break;
    case 5:
        printf("The weekday on 1st of Jan of %d is Friday." , input_year);
        break;
    case 6:
        printf("The weekday on 1st of Jan of %d is Saturday." , input_year);
        break;
    case 0:
        printf("The weekday on 1st of Jan of %d is Sunday." , input_year);
        break;
    
    default:
        printf("Error!!");
        break;
    }
    return 0;
}