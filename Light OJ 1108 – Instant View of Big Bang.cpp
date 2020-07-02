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

void dfs(int node,vector<int> &nodes,vector<bool> &taken,vector< vector< pii > > &graph)
{
    if(taken[node])
        return;
    nodes.eb(node),taken[node]=true;

    for(auto i:graph[node])
    {

            dfs(i.F,nodes,taken,graph);
    }
}

bool bellman(vector< vector <pii> > & graph,int n,int m,vector<int> &nodes)
{
    vi dist(n+1);
    for(int i=0;i<n;i++) dist[i]=1e7;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(auto k:graph[j])
                dist[k.F]=min(dist[k.F],dist[j]+k.S);
        }
    }

    bool check=false;
    vector<bool> taken(n+1);
    for(int j=0;j<n;j++)
    {
        for(auto i:graph[j])
        {
            if(dist[i.F]>dist[j]+i.S)
            {
                check=true;
                dist[i.F]=dist[j]+i.S;
                if(!taken[i.F])
                    dfs(i.F,nodes,taken,graph);
            }
        }
    }
    return check;
}


int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,m;
        cin>>n>>m;
        vector < vector <pii> > graph(n+1);
        vector<int> nodes;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[v].eb(u,w);
        }
        cout<<"Case "<<tc<<": ";
        if(bellman(graph,n,m,nodes))
        {
            sort(all(nodes));
            int sz=nodes.size();
            for(int i=0;i<sz-1;i++) cout<<nodes[i]<< " ";
            cout<<nodes[sz-1];
            cout<<endl;
        }
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}


