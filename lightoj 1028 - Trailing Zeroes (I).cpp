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
#define num   1000010
using namespace std;
bool isprime[num+10];
vector<ll> prime;
void sieve()
{
    prime.eb(2);
    for(ll i=3;i<=num;i+=2)
    {
        if(!isprime[i])
        {
            prime.eb(i);
            for(ll j=i*i;j<=num;j+=i)
            {
                isprime[j]=true;
            }
        }
    }
//    prime.push_back(2);
//    for(ll i=3;i<=num;i+=2)
//    {
//        if(!isprime[i])
//            prime.push_back(i);
//    }
}

ll divcnt(ll n)
{
    ll ans=1;
    for(auto i:prime)
    {
        if(i*i>n)
            break;

        if(n==1)
            break;
        ll cnt=1;
        while(n%i==0)
        {
            n=n/i;
            cnt++;
        }
        ans*=cnt;
    }
    if(n!=1)
        ans*=2;
    return ans-1;

}
int main()
{
    //KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    sieve();
    cin>>t;
    for(int cn=1;cn<=t;cn++)
    {
        ll n;
        scanf("%lli",&n);
        printf("Case %d: %lli\n",cn,divcnt(n));
    }
    return 0;
}


