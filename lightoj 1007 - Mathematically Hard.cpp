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
#define num   5000000+10
using namespace std;
ull phi[5000000+10];
int main()
{
    //KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    ull t;
    scanf("%llu",&t);
    for(ll i=0;i<=num;i++)
    {
        phi[i]=i;
    }
    for(ull i=2;i<=num;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(ull j=2*i;j<=num;j+=i)
            {
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
    for(ull i=1;i<=num;i++)
        phi[i]=(phi[i]*phi[i])+phi[i-1];
    for(ll cn=1;cn<=t;cn++)
    {
        ull a,b;
        scanf("%llu%llu",&a,&b);
        //cout<<phi[b]<< " "<<phi[a]<<endl;
        printf("Case %lld: %llu\n",cn,phi[b]-phi[a-1]);
    }
    return 0;
}


