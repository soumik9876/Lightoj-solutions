//Author - Soumik Roy
//Date & Time - August 29, 2020 1:43 PM
//Problem name - 1026 - Critical Links
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1026
//Time limit - 2000 ms
//Memory Limit - 32 MB    

#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;
vector<int> visittime,low;
vector<pair<int,int>> bridges;
bool visited[10010];
int timer=0,ans=0;
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first==b.first)
		return a.second<b.second;
	return a.first<b.first;
}
int dfs(int node,int p=-1)
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
			dfs(x,node);
			low[node]=min(low[node],low[x]);
			if(visittime[node]<low[x])
			{
				bridges.emplace_back(min(node,x),max(node,x));
				ans++;
			}
		}
	}
}
void solve()
{
	scanf("%d",&n);
	graph=vector<vector<int>> (n+1);
	visittime=vector<int> (n+1);
	low=vector<int> (n+1);
	bridges.clear();
	memset(visited,false,sizeof(visited));
	timer=0,ans=0;
	for(int i=0;i<n;i++)
	{
		int node,cnt,v;
		char temp;
		scanf("%d (%d)",&node,&cnt);
		for(int j=1;j<=cnt;j++)
		{
			scanf("%d",&v);
			graph[node].emplace_back(v);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			dfs(i);
	}
	sort(bridges.begin(),bridges.end(),comp);
	printf("%d critical links\n",ans);
	for(auto x: bridges)
	{
		printf("%d - %d\n",x.first,x.second);
	}
}
int main()
{
	int t;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case %d:\n",cn);
		solve();
	}
    return 0;
}

