#include <stdio.h>
int main(){
    int population = 100000 , new_pop = population;

    for (int i = 1; i < 11; i++)
    {
        new_pop = new_pop + (new_pop * 0.1) ;
        printf("Population after year %d is: %d\n",i,new_pop);
    }
    
    return 0;
}