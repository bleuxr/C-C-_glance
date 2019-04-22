#include<iostream>
#include<string>
#include<memory>
using namespace std;

class base{
public:
    base(int _a): a(_a){
        cout<<"Constructor"<<a<<endl;
    }
    ~base(){
        cout<<"Destructor"<<a<<endl;
    }
    int a;
};

int main(){
    unique_ptr<base> up1(new base(2));
    unique_ptr<base> up2=move(up1);
    cout<<up2->a<<endl;
    up2.reset();

    shared_ptr<base> sp1(new base(3));
    shared_ptr<base> sp2=sp1;
    cout<<sp2.use_count()<<endl;
    sp1.reset();
    cout<<sp2.use_count()<<endl;
    auto sp3=make_shared<base>(4);
    return 0;
}