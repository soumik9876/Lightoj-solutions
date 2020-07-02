#include<bits/stdc++.h>
#define ll                    long long int
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define MOD                   100000007
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
int n;
ll dp[52][1010][21];
int coins[52],have[52];
ll ways(int remain,int ind,int coincnt)
{
    if(ind>=n)
    {
        if(remain==0) return 1;
        return 0;
    }

    if(dp[ind][remain][coincnt]!=-1)
        return dp[ind][remain][coincnt];

    ll ans1=0,ans2=0;
    if(remain-coins[ind]>=0 && coincnt>0)
        ans1=ways(remain-coins[ind],ind,coincnt-1)%MOD;
    ans2=ways(remain,ind+1,have[ind+1])%MOD;
    //cout<<ans1<<" "<<ans2<<endl;
    return dp[ind][remain][coincnt]=(ans1+ans2)%MOD;
}
int main()
{
    //KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        memset(dp,-1,sizeof(dp));
        int k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&coins[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&have[i]);
        }
        printf("Case %d: %lld\n",j,ways(k,0,have[0]));
    }
    return 0;
}

