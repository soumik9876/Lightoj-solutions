//Author - Soumik Roy
//Date & Time - August 30, 2020 5:52 PM
//Problem name - 1300 - Odd Personality
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1300
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
vector< vi > graph;
vi visittime,low,col;
set< pii > bridges;
int timer=0,total=0,member=0;
bool visited[10010];
void cutbridge(int node,int p=-1)
{
	visittime[node]=low[node]=timer++;
	visited[node]=true;
	for(auto x: graph[node])
	{
		if(x==p) continue;
		if(visited[x]) low[node]=min(low[node],visittime[x]);
		else
		{
			cutbridge(x,node);
			low[node]=min(low[node],low[x]);
			if(low[x]>visittime[node])
			{
				bridges.insert(mp(x,node));
				bridges.insert(mp(node,x));
			}
		}
	}
}
bool dfs(int node)
{
	visited[node]=true;
	bool bicolor=true;
	for(auto x: graph[node])
	{
		if(bridges.find(mp(node,x))!=bridges.end())
			continue;
		if(col[x]==-1)
		{
			col[x]=1-col[node];
			bicolor=dfs(x)&bicolor;
		}
		else if(col[x]==col[node])
		{
			bicolor= false;
		}
	}
	member++;
	return bicolor;
}
void solve()
{
	scanf("%d %d",&n,&m);
	graph=vector< vi > (n+1);
	visittime=vi (n+1);
	low=vi (n+1);
	bridges.clear();
	memset(visited,false,sizeof(visited));
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].eb(v);
		graph[v].eb(u);
	}
	timer=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			cutbridge(i);
	}
	col=vi (n+1,-1);
	total=0;
	for(int i=0;i<n;i++)
	{
		member=0;
		if(col[i]==-1)
		{
			col[i]=0;
			if(!dfs(i) && member>1)
				total+=member;
		}
	}
	printf("%d\n",total);
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

