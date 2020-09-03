//Author - Soumik Roy
//Date & Time - September 02, 2020 9:30 PM
//Problem name - 1210 - Efficient Traffic System
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1210
//Time limit - 2000 ms
//Memory Limit - 32 MB    

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
#define bug(x)				  cout<<"  [ "#x<<" = "<<x<<" ]"<<endl;
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int dir[]={0,1,0,-1,1,0,-1,0};
int n,m,cnt=0;
vector<vi> graph,rgraph;
bool visited[20010];
vi tout,scc;
void dfs1(int node)
{
	visited[node]=true;
	for(auto x: graph[node])
	{
		if(!visited[x])
			dfs1(x);
	}
	tout.eb(node);
}
void dfs2(int node,vector<vi> &g)
{
	scc[node]=cnt;
	for(auto x: g[node])
	{
		if(!scc[x])
			dfs2(x,g);
	}
}

void solve()
{
	cin>>n>>m;
	graph=vector<vi> (n+1);
	rgraph=vector<vi> (n+1);
	tout.clear();
	memset(visited,false,sizeof(visited));
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].eb(v);
		rgraph[v].eb(u);
	}

	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs1(i);
		}
	}
	scc=vi (n+1);
	cnt=1;
	for(int i=0;i<n;i++)
	{
		int node=tout[n-i-1];
		if(!scc[node])
		{
			dfs2(node,rgraph);
			cnt++;
		}
	}
	if(cnt==2) 
	{
		cout<<0<<endl;
		return;
	}
	
	bool in[cnt+1]={},out[cnt+1]={};
	int incnt=0,outcnt=0;
	for(int i=1;i<=n;i++)
	{
		for(auto x: graph[i])
		{
			if(scc[i]!=scc[x])
			{
				out[scc[i]]=true;
				in[scc[x]]=true;
			}
		}
	}
	for(int i=1;i<cnt;i++)
		incnt+=!in[i],outcnt+=!out[i];
	int total=max(incnt,outcnt);
	
	cout<<total<<endl;
}
int main()
{
    KAMEHAMEHA
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		cout<<"Case "<<cn<<": ";
		solve();
	}
    return 0;
}

