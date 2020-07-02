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
    //KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int q,a,b;
        vi points;
        scanf("%d%d",&n,&q);
        for(int j=0,temp;j<n;j++)
        {
            scanf("%d",&temp);
            points.eb(temp);
        }
        printf("Case %d:\n",i);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            int low=lower_bound(all(points),a)-points.begin();
            int high=upper_bound(all(points),b)-points.begin();
            int diff=high-low;
            if(high==n-1 && points[high]<=b)
                diff++;
            printf("%d\n",diff);
        }
    }
    return 0;
}


