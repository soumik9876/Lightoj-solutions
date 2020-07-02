#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<(int)n/2<<" "<<n-(int)n/2<<endl;
    }
    return 0;
}
