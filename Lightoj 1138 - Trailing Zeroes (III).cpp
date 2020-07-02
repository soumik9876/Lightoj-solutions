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
int cntzero(int n)
{
    int cnt=0,div=5;
    while(div<=n)
    {
        cnt+=(n/div);
        div*=5;
    }
    return cnt;
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    ll t;
    cin>>t;
    for(int cn=1;cn<=t;cn++)
    {
        ll n;
        cin>>n;
        ll low=0,high=5*n+5,mid;

        while(low<=high)
        {
            mid=(high+low)/2;
            if(low>=high-1 && cntzero(mid)!=n)
            {
                mid=-1;
                break;
            }
            //cout<<high<< " "<<low<< " "<<mid<<endl;
            if(cntzero(mid)==n)
            {
                while(cntzero(mid-1)==n)
                    mid--;
                break;
            }
            else if(cntzero(mid)>n)
                high=mid-1;
            else
                low=mid+1;
        }
        cout<<"Case "<<cn<< ": ";
        if(mid==-1)
            cout<<"impossible"<<endl;
        else
            cout<<mid<<endl;

    }
    return 0;
}


