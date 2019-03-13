#include<iostream>
using namespace std;

class Point
{
    private:
        double x;
        double y;
    public:
        Point(double a=0,double b=0);
        void Set(double a,double b);
        void Show(){
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
};

Point::Point(double a,double b)
{
    x=a;
    y=b;
}

void Point::Set(double a,double b)
{
    x=a;
    y=b;
}

// void Point::Show()
// {
//     cout<<"("<<x<<","<<y<<")"<<endl;
// }

int main(){
    Point v(6,18);
    v.Show();
}