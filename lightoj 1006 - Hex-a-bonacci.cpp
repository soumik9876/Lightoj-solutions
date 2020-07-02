#include<cstdio>
using namespace std;
int a, b, c, d, e, f;
int arr[10000];
int fn( int n ) {
    if( n == 0 )
    {
        arr[n]=a;
        return arr[n];
    }
    if( n == 1 )
    {
        arr[n]=b;
        return arr[n];
    }
    if( n == 2 )
    {
        arr[n]=c;
        return arr[n];
    }
    if( n == 3 )
    {
        arr[n]=d;
        return arr[n];
    }
    if( n == 4 )
    {
        arr[n]=e;
        return arr[n];
    }
    if( n == 5 )
    {
        arr[n]=f;
        return arr[n];
    }
    return arr[n]=( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
