//Author - Soumik Roy
//Date & Time - August 20, 2020 4:51 PM
//Problem name - 1185 - Escape
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1185
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
vector<vi> graph;
bool visitparity[101][3];
void dfs(int node,int vpar)
{
	int nextpar=1;
	if(vpar==1)
		nextpar=2;
	visitparity[node][vpar]=1;
	for(auto x : graph[node])
	{
		if(visitparity[x][nextpar]) continue;
		dfs(x,nextpar);
	}
}
void solve()
{
	ll n,m;
	cin>>n>>m;
	graph.resize(n+1);
	for (int i = 1; i <= n; i++)
	{
		graph[i].clear();
	}
	memset(visitparity,false,sizeof(visitparity));
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].eb(v);
		graph[v].eb(u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(visitparity[i][2]) ans++;
	}
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

