#include <stdio.h>
int main(){
    float height , weight,bmi;
    h_validator:
    printf("Enter height in Meters(m): ");
    scanf("%f",&height);
    if(height > 2.2 || height < 1.2){
        printf("Please Enter a height between 1.2 to 2.2 Meters! ");
        goto h_validator;
    }
    printf("\nEnter your weight in KG: ");
    scanf("%f",&weight);
    bmi = weight/(height*height);
    if (bmi< 15	)
    {
        printf("Starvation.");
    }
    else if(bmi>15.1 && bmi<17.5) {
        printf("Anorexic.");
    }
    else if(bmi>17.6 && bmi<18.5) {
        printf("Underweight.");
    }
    else if(bmi>18.6 && bmi<24.9) {
        printf("Ideal.");
    }
    else if(bmi>25 && bmi<29.9) {
        printf("Overweight.");
    }
    else if(bmi>30 && bmi<39.9) {
        printf("Obese.");
    }
    else if(bmi>40.0) {
        printf("Morbidity Obese.");
    }
    
    

    return 0;
}