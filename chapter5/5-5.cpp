#include<iostream>
using namespace std;

template <typename T>
struct Point{
    T x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};

template <typename T>
Point<T> operator + (const Point<T>& A,const Point<T>& B){
    return Point<T>(A.x+B.x,A.y+B.y);
}

template <typename T>
ostream& operator << (ostream &out,const Point<T>& P){
    out<<"("<<P.x<<","<<P.y<<")";
    return out;
}

template<typename T>
T sum(T* begin,T* end){
    T *p=begin;
    T ans=0;
    for(T *p=begin;p!=end;p++)
        ans=ans+*p;
    return ans;
}

int main(){
    double a[]={1.1,2.2,3.3,4.4};
    cout<<sum(a,a+4)<<"\n";


    Point<int> b[]={Point<int>(1,2),Point<int>(3,4)};
    cout<<sum(b,b+2)<<"\n";
    return 0;
}