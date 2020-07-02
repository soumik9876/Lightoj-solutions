#include<bits/stdc++.h>
#define ll                    long long int
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define MOD                   1000000007
#define vi                    vector<int>
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define eb                    emplace_back
#define ull                   unsigned long long
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll n;
        cin>>n;
        ll root=ceil(sqrt(n));
        ll upper=root*root,low=(root-1)*(root-1);
        ll x,y,half=(upper-low)/2;

        if(n-low<=half)
        {
            x=root,y=n-low;
        }
        else
        {
            x=root-(n-((upper+low)/2))+1,y=root;
        }
        if(root%2==0)
            swap(x,y);
        cout<<"Case "<<i<<": "<<x<< " "<<y<<endl;
    }
    return 0;
}


