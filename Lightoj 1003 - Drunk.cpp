//Author - Soumik Roy
//Date & Time - September 02, 2020 2:16 PM
//Problem name - 1003 - Drunk
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1003
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
int m;
unordered_map<string,int> nodes;
vector<vi> graph;
vi visited;
bool dfs(int node)
{
	visited[node]=1;
	for(auto x: graph[node])
	{
		if(visited[x]==0)
		{
			if(dfs(x))
				return true;
		}
		else if(visited[x]==1)
			return true;
	}
	visited[node]=2;
	return false;
}
void solve()
{
	cin>>m;
	graph=vector<vi> (2*m+1);
	nodes.clear();
	visited=vi (2*m+1);
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		string s,t;
		cin>>s>>t;
		if(nodes.find(s)==nodes.end())
			nodes[s]=cnt++;
		if(nodes.find(t)==nodes.end())
			nodes[t]=cnt++;
		graph[nodes[s]].eb(nodes[t]);
	}
	for(int i=0;i<cnt;i++)
	{
		if(!visited[i])
		{
			if(dfs(i))
			{
				cout<<"No"<<endl;
				return;
			}
		}
	}
	cout<<"Yes"<<endl;
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

