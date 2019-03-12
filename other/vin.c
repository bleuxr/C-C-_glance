#include "stdio.h"
#define GD_OK  1
#define GD_ERR -1
int VinCalc(char *Vin,char *reslt)
{
unsigned int i = 0;
unsigned int sum =0;
unsigned int check = 0;
char temp=0;
unsigned int j = 0;

char jianquan[26][2] = {
{'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},
{'G',7},{'H',8},{'I',0},{'J',1},{'K',2},{'L',3},
{'M',4},{'N',5},{'O',0},{'P',7},{'Q',8},{'R',9},
{'S',2},{'T',3},{'U',4},{'V',5},{'W',6},{'X',7},
{'Y',8},{'Z',9}};
char pos[17]={8,7,6,5,4,3,2,10,0,9,8,7,6,5,4,3,2};

for(i=0;i<17;i++)
{
if(Vin[i]>='a'&&Vin[i]<='z')
{
temp = Vin[i]-0x20;
}
else if((Vin[i]>='A')&&(Vin[i]<='Z'))
{
temp = Vin[i];
}
else if((Vin[i]>='0')&&(Vin[i]<='9'))temp = Vin[i]-'0';
else return GD_ERR;

if((temp>='A')&&(temp<='Z'))
{
for(j=0;j<26;j++)
{
if(temp == jianquan[j][0])
temp = jianquan[j][1];
}
}
check += temp*pos[i];
}
*reslt = check%11;
return GD_OK;
}
void main(void)
{
char check = 0;
char* Vin="UU6JA69691D713820";
VinCalc(Vin,&check);
printf("校验位是:%d",check);
}