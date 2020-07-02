#include<bits/stdc++.h>
#define endl '\n'
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll long long int
#define loop(a,b)           for(int i=a;i<=b;++i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
#define eb                    emplace_back
using namespace std;
vll graph[105];
ll sd[105],dd[105];
ll n,r,u,v;
queue<ll> q;
void FAST_IO();
void bfs(ll s,ll ara[]);
int main()
{
    //_time_
   //FAST_IO();
   ll c=1;
    tcase()
    {
        ll s,d;
        cin>>n>>r;
        memset(graph,0,sizeof(graph));
        memset(sd,INT_MAX,sizeof(sd));
        memset(dd,INT_MAX,sizeof(dd));
        for(ll i=0;i<r;i++)
        {
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        cin>>s>>d;
        bfs(s,sd);

        bfs(d,dd);
        //for(ll i=0;i<n;i++)
            //cout<<sd[i]<<" "<<dd[i]<<endl;
        ll maxx=0;
        for(ll i=0;i<n;i++)
        {
            if(sd[i]+dd[i]>maxx)
                maxx=sd[i]+dd[i];
        }
        cout<<"Case "<<c++<<": "<<maxx<<endl;

    }


   // show
    return 0;
}
void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
#ifndef _offline
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
void bfs(ll s,ll ara[])
{
    ara[s]=0;
    q.push(s);
    while(!q.empty())
    {

        ll v=q.front();
        q.pop();
        ll sz=graph[v].size();
        //cout<<v<<endl;
        for(ll i=0;i<sz;i++)
        {
            if(ara[graph[v][i]]==-1)
            {
                ara[graph[v][i]]=ara[v]+1;
                q.push(graph[v][i]);
            }
        }
    }

}
