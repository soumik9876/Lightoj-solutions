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
#define N  100001
using namespace std;
bool isprime[N+50];
vll prime;
ll bigmod(ll n,ll p)
{
    if(p==0)
        return 1;
    ll x=bigmod(n,p/2);
    x=(x*x)%MOD;
    if(p%2)
        x=(x*n)%MOD;
    //cout<<p<<" "<<x<<endl;
    return x;
}
void sieve()
{
    for(int i=3;i*i<=N;i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                isprime[j]=true;
            }
        }
    }

    prime.eb(2);
    for(int i=3;i<=N;i+=2)
    {
        if(!isprime[i])
            prime.eb(i);
    }
}

ll sod(ll n,ll m)
{
    ll p=1;
    if(n==MOD)
        return p;
    for(auto i: prime)
    {
        //cout<<i<<endl;
        if(i*i>n || n==1)
            break;

        ll cnt=0;

        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        cnt*=m;
        cnt++;
        ll a=bigmod(i,cnt);
        
        a=a-1;
        ll div=bigmod(i-1,MOD-2);
        a=(a*div)%MOD;
		//cout<<i<< " "<<cnt<< " "<<a<<endl;
        p=(p*a)%MOD;
    }
    if(n!=1)
    {
        ll a=bigmod(n,m+1);
		//cout<<a<<endl;
        a=a-1;
        ll div=bigmod(n-1,MOD-2);
        a=(a*div)%MOD;
		//cout<<n<< " "<<m<< " "<<a<<endl;
        p=(p*a)%MOD;
    }
    return p;
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    //cout<<bigmod(2,6)<<endl;
    cin>>t;
    sieve();
    for(int cn=1;cn<=t;cn++)
    {
        ll n,m;
        cin>>n>>m;
        cout<<"Case "<<cn<<": "<<sod(n,m)<<endl;
    }
    return 0;
}



