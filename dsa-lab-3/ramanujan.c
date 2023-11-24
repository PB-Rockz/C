#include <stdio.h>
#include <math.h>

int isRamanujan(int num) {
    int count = 0;
    
    for (int a = 1; a <= cbrt(num); a++) {
        int a3 = a * a * a;
        int b3 = num - a3;
        
        if (b3 < 0) {
            break;
        }
        
        int b = cbrt(b3);
        if (b * b * b == b3) {
            count++;
            if (count == 2) {
                return 1;
            }
        }
    }
    
    return 0;
}

int main() {
    int limit;
    
    printf("Enter a limit: ");
    scanf("%d", &limit);

    printf("Ramanujan numbers up to %d:\n", limit);

    for (int num = 2; num <= limit; num++) {
        if (isRamanujan(num)) {
            printf("%d\n", num);
        }
    }

    return 0;
}
