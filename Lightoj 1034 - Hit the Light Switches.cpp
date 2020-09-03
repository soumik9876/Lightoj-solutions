//Author - Soumik Roy
//Date & Time - September 02, 2020 4:50 PM
//Problem name - 1034 - Hit the Light Switches
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1034
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
vi tout;
bool visited[10010];
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
void dfs2(int node)
{
	visited[node]=true;
	for(auto x: graph[node])
	{
		if(!visited[x])
			dfs2(x);
	}
}
void solve()
{
	scanf("%d %d",&n,&m);
	graph=vector<vi> (n+1);
	memset(visited,false,sizeof(visited));
	tout.clear();
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].eb(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
			dfs1(i);
	}
	memset(visited,false,sizeof(visited));
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int node=tout[n-i-1];
		if(!visited[node])
		{
			dfs2(node);
			cnt++;
		}
	}
	printf("%d\n",cnt);
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

