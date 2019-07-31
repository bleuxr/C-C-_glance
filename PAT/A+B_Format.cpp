#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int a,b,sum,len,first,count,i;
    char s[8];
    if(scanf("%d%d",&a,&b)==2){
        sum=a+b;
        if(sum<0){
            printf("-");
            sum=abs(sum);
        }
        sprintf(s,"%d",sum);
        len=strlen(s);
        first=len%3;
        count=len/3;
        i=0;
        if(first==1){
            printf("%c",s[i]);
            i++;
        }
        else if(first==2){
            printf("%c%c",s[i],s[i+1]);
            i+=2;
        }
        else if(first==0){
            printf("%c%c%c",s[i],s[i+1],s[i+2]);
            i+=3;
            count--;
        }
        while(count){
            printf(",%c%c%c",s[i],s[i+1],s[i+2]);
            i+=3;
            count--;
        }
    }

    return 0;
}