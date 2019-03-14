#include<iostream>
using namespace std;

bool isvalid(int arr[]){
    int hour=arr[0]*10+arr[1];
    int minute=arr[2]*10+arr[3];
    int second=arr[4]*10+arr[5];
    if(hour>=0&&hour<=24)
    {
        if(hour==24&&minute==0&&second==0)
            return true;
        else if(minute>=0&&minute<=59&&second>=0&&second<=59)
            return true;
        else
            return false;
    }
    return false;
}

int compare(int a[],int b[])
{
    for(int i=0;i<6;i++)
        if(a[i]>b[i])
            return 1;
        else if(a[i]<b[i])
            return -1;
    return 0;
}

int main(){
    int max[]={-1,-1,-1,-1,-1,-1};
    int min[]={9,9,9,9,9,9};
    int arr[6]={0};
    int used[6]={0};
    for(int i=0;i<6;i++)
        cin>>arr[i];

    for(int l1=0;l1<6;l1++){
        for(int l2=0;l2<6;l2++){
            if(l2==l1) continue;
            for(int l3=0;l3<6;l3++){
                if(l3==l1||l3==l2) continue;
                for(int l4=0;l4<6;l4++){
                    if(l4==l1||l4==l2||l4==l3) continue;
                    for(int l5=0;l5<6;l5++){
                        if(l5==l1||l5==l2||l5==l3||l5==l4) continue;
                        for(int l6=0;l6<6;l6++){
                            if(l6==l1||l6==l2||l6==l3||l6==l4||l6==l5) continue;
                            int time[]={arr[l1],arr[l2],arr[l3],arr[l4],arr[l5],arr[l6]};
                            if(isvalid(time)){
                                if(compare(time,max)==1){
                                    for(int i=0;i<6;i++)
                                        max[i]=time[i];
                                }
                                if(compare(time,min)==-1){
                                    for(int i=0;i<6;i++)
                                        min[i]=time[i];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(isvalid(max)){
        for(int i=0;i<6;i++)
            cout<<max[i];
        cout<<endl;        
    }

    if(isvalid(min)){
        for(int i=0;i<6;i++)
            cout<<min[i];
        cout<<endl;        
    }

    return 0;
}
