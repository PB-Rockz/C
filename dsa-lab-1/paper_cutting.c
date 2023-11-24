#include <stdio.h>
int length[9],breadth[9] ;
void compute(int x,int y,int i) {
    if(i>9)
    {
        return ;
    }
    if(x>y)
    {
        i++;
        length[i]=x/2;
        breadth[i]=y;
        return compute(length[i],breadth[i],i);
    }
    else
    {
        i++;
        length[i]=x;
        breadth[i]=y/2;
        return compute(length[i],breadth[i],i);
    }

}
int main(){
    int flag = 0;
    // printf("Enter Size of Paper: ");
    // scanf("%d %d", &length[0],&breadth[0]);
    length[0] = 1189;
    breadth[0]=841;
    compute(length[0],breadth[0],flag);
    for (int i = 0; i < 9; i++ )
    {
        printf("Dimensions of A%d are %d x %d\n",i,length[i],breadth[i]);
    }
    return 0;
}