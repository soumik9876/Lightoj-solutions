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
int n,m;
const int INF=1e9;

int dijktra(vector< vector< pii > > graph)
{
    vi dist(n+1,INF);
    dist[1]=0;
    priority_queue< pii,vector<pii>,greater< pii > > pq;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        int node=pq.top().S;
        pq.pop();
        for(auto x: graph[node])
        {
            if(dist[x.F]>dist[node]+x.S)
            {
                dist[x.F]=dist[node]+x.S;
                pq.push(mp(dist[x.F],x.F));
            }
        }
    }
    return dist[n];
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    for(int cn=1;cn<=t;cn++)
    {
        
        cin>>n>>m;
        vector< vector< pii > > graph(n+1);
        
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].eb(v,w);
            graph[v].eb(u,w);
        }
        int ans=dijktra(graph);
        cout<<"Case "<<cn<<": ";
        if(ans!=INF)
            cout<<ans<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}

