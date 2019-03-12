#include <stdio.h>
int main()
{
    //min,max need to be initialized
    //fixed in 2-10.c
    int x,n=0,min,max,s=0;
    while(scanf("%d",&x)==1) 
    {
        s+=x;
        if(x<min) min=x;
        if(x>max) max=x;
        n++;
    }
    printf("%d %d %.3f\n",min,max,(double)s/n);
    return 0;
}