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
void pfcnt(ll n,map<ll,ll> &cnt)
{
    while(n%2==0)
    {
        cnt[2]++;
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2)
    {

        while(n%i==0)
        {
            cnt[i]++;
            n/=i;
        }
        //cout<<i<< " "<<cnt[i]<<endl;
    }
    if(n>2)
        cnt[n]++;
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
        ll a,b,L;
        cin>>a>>b>>L;
        ll lcm=(a*b)/__gcd(a,b);
        cout<<"Case "<< cn<< ": ";
        if(L%lcm!=0)
            cout<<"impossible"<<endl;
        else
        {
            //ll high=lcm+10,low=0,mid;
//            while(low<=high)
//            {
//                mid=(low+high)/2;
//                ll val=(mid*lcm)/(__gcd(mid,lcm));
//                cout<<high<< " "<<low<< " "<<mid<< " "<<val<<endl;
//                if(val>=L)
//                    high=mid-1;
//                else
//                    low=mid+1;
//            }
//            ll last=L/lcm;
//            while(1)
//            {
//                int g=__gcd(last,lcm);
//                int cur=L/(lcm/g);
//                //cout<<cur<< " "<<last<<endl;
//
//                if(cur==last)
//                    break;
//                else
//                    last=cur;
//            }
//            cout<<last<<endl;
            map<ll , ll> Lcnt,lcmcnt;
            pfcnt(lcm,lcmcnt);
            pfcnt(L,Lcnt);
            //cout<<lcm<<endl;
            ll num=1;
            for(auto i:Lcnt)
            {
                cout<<i.F<<  " "<<i.S<< " "<<lcmcnt[i.F]<<endl;
                if(lcmcnt[i.F]<i.S)
                {
                    for(int k=1;k<=i.S;k++)
                        num*=i.F;
                }
            }
            cout<<num<<endl;
        }
    }
    return 0;
}


