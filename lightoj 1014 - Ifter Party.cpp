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
void solve(int cn)
{
    ll p,l;
    scanf("%lld%lld",&p,&l);
    ll num=p-l;
    printf("Case %d:",cn);
    if(num<=l)
    {
        printf(" impossible\n");
        return;
    }
    if(num==0)
    {
        printf(" 1\n");
        return;
    }
    vll div1,div2;
    for(ll i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            if(i==num/i && i>l)
                div1.eb(i);
            else
            {
                if(i>l)
                    div1.eb(i);
                if((num/i)>l)
                    div2.eb(num/i);
            }
        }
    }
    ll s1=div1.size(),s2=div2.size();
    //sort(all(div1));
    //cout<<div1[0]<< " "<<div2[0]<<endl;
    for(ll i=0;i<s1;i++)
        printf(" %lld",div1[i]);
    for(ll i=s2-1;i>=0;i--)
        printf(" %lld",div2[i]);
    printf("\n");
}
int main()
{
    //KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }
    return 0;
}


