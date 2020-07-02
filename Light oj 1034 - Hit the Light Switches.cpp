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
int dfs(int start,vector< vi > &graph,bool *visited,vector< pii > &finish,int &time,bool check)
{
    visited[start]=true;
//    if(!check) time++;
    if(graph[start].size()==0)
        finish[start].F=1;
    for(auto i:graph[start])
    {
        if(!visited[i])
        {
            finish[start].F+=dfs(i,graph,visited,finish,time,check)+1;
        }
        else
            finish[start].F+= finish[i].F+1;
        //finish[start].F++;
    }
    if(!check)
    {
        //cout<<start<< " "<<finish[start].F<<endl;
        finish[start].S=start;
        return finish[start].F;
    }

}
int main()
{
    KAMEHAMEHA
    #ifdef _soumik
        freopen("input.txt", "r", stdin);
    #endif
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,m;
        cin>>n>>m;
        vector< vi >  graph(n+10);
        vector< pii > finish(n+10);
        bool visited[n+10];
        memset(visited,false,sizeof(visited));
        int time=1;
        vector<bool> exist(n+10);
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].eb(v);
            //exist[u]=true,exist[v]=true;
        }
        for(int i=1;i<=n;i++)
        {
            time=1;
            memset(visited,false,sizeof(visited));
            //if(!visited[i])
                dfs(i,graph,visited,finish,time,false);
        }
        memset(visited,false,sizeof(visited));
        int cnt=0;
        sort(all(finish),greater<pii> () );
//        for(int i=0;i<=n;i++)
//            cout<<finish[i].F<<" "<<finish[i].S<<endl;
        for(int i=0;i<n;i++)
        {
            if(!visited[finish[i].S] )
                dfs(finish[i].S,graph,visited,finish,time,true),cnt++;
        }
        cout<<"Case "<<c<<": "<<cnt<<endl;
        //cout<<cnt<<endl;

    }
    return 0;
}


