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
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
#define eb                    emplace_back
#define ull                   unsigned long long
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void bfs(int start,vector<vector< pii > > &graph,vi &dist);
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,m,start;
        cin>>n>>m;
        vector< vector< pii > >graph(n+10);
        vi dist(n+10);
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].eb(v,w);
            graph[v].eb(u,w);
        }
        for(int i=0;i<n;i++)
        {
            dist[i]=INT_MAX;
        }
        cin>>start;
        bfs(start,graph,dist);
        cout<<"Case "<<c<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX)
                cout<<"Impossible"<<endl;
            else
                cout<<dist[i]<< endl;
        }
    }
    return 0;
}
void bfs(int start,vector<vector< pii > > &graph,vi &dist)
{
    queue<int> q;
    q.push(start);
    dist[start]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto i:graph[u])
        {
            int mx=max(dist[u],i.S);
            if(mx<dist[i.F])
            {
                dist[i.F]=mx;
                q.push(i.F);
            }
        }
    }
}

