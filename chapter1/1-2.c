#include <stdio.h>
int main()
{   
    //same code but different outcome
    printf("%.1f\n",8/5);

    printf("%.1f\n",8.0/5.0);
    printf("%.2f\n",8.0/5.0);
    
    //same code but different outcome
    printf("%.1f\n",8/5);
    printf("%d\n",8.0/5.0);
    return 0;
}