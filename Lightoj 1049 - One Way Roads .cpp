#include<bits/stdc++.h>
#define endl '\n'
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll                    long long int
#define loop(a,b)             for(int i=a;i<=b;++i)
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

using namespace std;
vll graph[103];
bool visited[103][103];
ll cost[103][103];
void dfs(ll n);
ll n,u,v,c,pos=0,neg=0;
void FAST_IO();
int main()
{
    //_time_
   //FAST_IO();
   int cnt = 1;
    tcase()
    {
        cin>>n;
        pos=0,neg=0;
        for(ll i=1;i<=n;i++)
            graph[i].clear();
        memset(cost,0,sizeof(cost));
        memset(visited,0,sizeof(visited));

        for(ll i=0;i<n;i++)
        {
            cin>>u>>v>>c;
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u][v]=0;
            cost[v][u]=c;
        }

//        for(int i = 1; i <=n; i++) {
//
//            dfs(i);
//        }

        dfs(1);

        cout<<"Case " << cnt++ << ": " << min(pos,neg)<<endl;
    }


   // show
    return 0;
}
void dfs(ll n)
{

    int sz = graph[n].size();
    for(int i = 0; i < sz; i++) {

        ll t = graph[n][i];
        if(!visited[n][t]) {

            pos += cost[n][t];
            neg += cost[t][n];
            visited[n][t] = true;
            visited[t][n] = true;
            dfs(t);
        }
    }


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

