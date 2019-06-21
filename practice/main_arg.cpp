#include <iostream>

using namespace std;

// ./a.out arug1 arug2 arug3
int main(int argc, char * argv[]){
    cout<<"There are "<<argc<<" arguments\n";
    for(int i=0;i<argc;++i){
        cout<<argv[i]<<endl;
    }

    return 0;
}