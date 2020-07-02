#include<bits/stdc++.h>
#define ll                    long long int
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define MOD                   1000003
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
#define num 1000000+2
using namespace std;
ll fact[num+10],t,modInverse[num+10];
ll bigmod(ll n,ll power)
{
    if(modInverse[n]!=0)
        return modInverse[n];
    if(power==0)
        return 1LL;
    ll ans=bigmod(n,power/2);
    ans=(ans*ans)%MOD;
    if(power%2)
        ans=(ans*n)%MOD;
    return modInverse[n]=ans;
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    fact[0]=1;
    for(int i=1;i<=num;i++)
    {
        fact[i]=(i*fact[i-1])%MOD;
    }
    modInverse[1]=1;
    //cout<<bigmod(fact[2],MOD-2)%MOD<<endl;
    for(int i=2;i<=num;i++)
        bigmod(i,MOD-2);
    cin>>t;
    for(ll cn=1;cn<=t;cn++)
    {
        ll n,k,ans;
        cin>>n>>k;
        ans=(fact[n]*(modInverse[fact[k]]%MOD)*(modInverse[fact[n-k]]%MOD));
        //cout<<fact[n]<< " "<<modInverse[fact[k]]<< " "<<modInverse[fact[n-k]]<<endl;
        cout<<"Case "<<cn<<": "<<ans%MOD<<endl;
    }
    return 0;
}


