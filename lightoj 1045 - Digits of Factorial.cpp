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
#define num                     1e6+10
using namespace std;
ll logn(ll n,ll base)
{
    return (ll)(log(n) / log(base));
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    ll t;
    cin>>t;
    vector<double> logs(num);
    logs[0]=0;
    for(ll i=1;i<num;i++)
        logs[i]+=log(i)+logs[i-1];
    for(ll cn=1;cn<=t;cn++)
    {
        ll n,base;
        cin>>n>>base;
        ll ans=(logs[n]/log(base))+1;
        cout<<"Case "<<cn<<": "<<ans<<endl;
    }
    return 0;
}


