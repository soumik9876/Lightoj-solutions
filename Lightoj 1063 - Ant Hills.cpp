//Author - Soumik Roy
//Date & Time - August 29, 2020 12:35 AM
//Problem name - 1063 - Ant Hills
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1063
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
vector< vi > graph;
vi visittime;
vi low;
int timer=0,ans=0;
bool visited[10010];
bool iscutpoint[10010];
void dfs(int node,int p=-1)
{
	visited[node]=true;
	visittime[node]=low[node]=timer++;
	int childs=0;
	for(auto x: graph[node])
	{
		if(x==p) continue;
		if(visited[x])
		{
			low[node]=min(low[node],visittime[x]);
		}
		else
		{
			dfs(x,node);
			low[node]=min(low[node],low[x]);
			if(p!=-1 && visittime[node]<=low[x] && !iscutpoint[node])
			{
				iscutpoint[node]=true;
				ans++;
			}
			childs++;
		}
	}
	if(p==-1 && childs>1 && !iscutpoint[node])
	{
		iscutpoint[node]=true;
		ans++;
	}
}
void solve()
{
	int n,m;
	cin>>n>>m;
	graph=vector<vi> (n+1);
	visittime=vi (n+1,-1);
	memset(visited,false,sizeof(visited));
	memset(iscutpoint,false,sizeof(iscutpoint));
	low=vi(n+1,-1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].eb(v);
		graph[v].eb(u);
	}
	timer=0,ans=0;
	
	dfs(1);
	cout<<ans<<endl;
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

