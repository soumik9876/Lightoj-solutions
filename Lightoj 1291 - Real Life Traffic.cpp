//Author - Soumik Roy
//Date & Time - August 29, 2020 11:18 PM
//Problem name - 1291 - Real Life Traffic
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1291
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
int n,m;
vector<vi> graph;
set<pair<int,int>> cutedge;
vi inpoint,visittime,low;
bool visited[10010];
int timer=0;
void cutedges(int node,int p=-1)
{
	visited[node]=true;
	visittime[node]=low[node]=timer++;
	for(auto x: graph[node])
	{
		if(x==p) continue;
		if(visited[x])
			low[node]=min(low[node],visittime[x]);
		else
		{
			cutedges(x,node);
			low[node]=min(low[node],low[x]);
			if(visittime[node]<low[x])
			{
				cutedge.insert(mp(node,x));
				cutedge.insert(mp(x,node));
				inpoint[node]++;
				inpoint[x]++;
			}
		}
	}
}
int dfs(int node)
{
	visited[node]=true;
	int total=inpoint[node];
	for(auto x: graph[node])
	{
		if(visited[x] || cutedge.find(mp(node,x))!=cutedge.end())
			continue;
		total+=dfs(x);
	}
	return total;
}
void solve()
{
	scanf("%d %d",&n,&m);
	graph=vector<vi> (n+1);
	inpoint=vi (n+1);
	visittime=vi (n+1);
	low=vi (n+1);
	cutedge.clear();
	memset(visited,false,sizeof(visited));
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].eb(v);
		graph[v].eb(u);
	}
	timer=0;
	cutedges(0);
	memset(visited,false,sizeof(visited));
	int ans=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			int deg=dfs(i);
			if(deg==1)
			{
				ans++;
			}
		}
	}
	ans=(ans/2)+(ans%2);
	printf("%d\n",ans);
}
int main()
{
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case %d: ",cn);
		solve();
	}
    return 0;
}

