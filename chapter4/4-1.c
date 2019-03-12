typedef struct{double x,y;} Point;

double dist(Point a,Point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}

long long factorial(int n){
    long long m=1;
    for(int i=1;i<=n;i++)
        m*=i;
    return m;
}

long long C(int n,int m)
{
    return factorial(n)/(factorial(m)*factorial(n-m));
}

//n!=1&&n can't be too large
int is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return 0;
    return 1;
}

//improve
int is_prime(int n)
{
    if(n<=1) return 0;
    int m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++)
        if(n%i==0) return 0;
    return 1;
}
