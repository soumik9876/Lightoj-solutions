#include<iostream>
using namespace std;
int main()
{
    int t,x,y,x1,y1,x2,y2,m,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cin>>m;
        cout<<"Case "<<i<<":\n";
        while(m--)
        {
            cin>>x>>y;
            if((x>x1 && x<x2) && (y>y1 && y<y2))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
