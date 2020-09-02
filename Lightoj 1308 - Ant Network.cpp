//Author - Soumik Roy
//Date & Time - September 01, 2020 4:12 PM
//Problem name - 1308 - Ant Network
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1308
//Time limit - 2000 ms
//Memory Limit - 32 MB    

#include<bits/stdc++.h>
#define ll                    long long int
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
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
const ull mod=(ull)pow(2ULL,64ULL);
int n,m;
vector<vi> graph;
vi low,visittime;
bool visited[10010],cutpoint[10010];
int timer=0,tcut=0;
set<int> foundcut;
void detectcutpoints(int node,int p=-1)
{
	visited[node]=true;
	visittime[node]=low[node]=timer++;
	int childs=0;
	for(auto x: graph[node])
	{
		if(x==p) continue;
		if(visited[x]) low[node]=min(low[node],visittime[x]);
		else
		{
			detectcutpoints(x,node);
			low[node]=min(low[node],low[x]);
			if(p!=-1 && visittime[node]<=low[x] && !cutpoint[node])
			{
				cutpoint[node]=true;
				tcut++;
			}
			childs++;
		}
	}
	if(p==-1 && childs>1)
		cutpoint[node]=true,tcut++; 
}

ull dfs(int node)
{
	visited[node]=true;
	//cout<<node<<" "<<cutpoint[node]<<endl;
	ull nodes=0,cuts=0;
	for(auto x: graph[node])
	{
		if(visited[x]) continue;
		if(cutpoint[x])
		{
			foundcut.insert(x);
			continue;
		}
		ull n=dfs(x);
		if(!n) return n;
		nodes+=n; 
	}
	return nodes+1;
}

void solve()
{
	scanf("%d %d",&n,&m);
	graph=vector< vi > (n+1);
	low=vi (n+1);
	visittime=vi(n+1);
	memset(visited,false,sizeof(visited));
	memset(cutpoint,false,sizeof(cutpoint));
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].eb(v);
		graph[v].eb(u);
	}
	timer=0,tcut=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			detectcutpoints(i);
	}
	ull cnt=0,ways=1;
	memset(visited,false,sizeof(visited));
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && !cutpoint[i])
		{
			foundcut.clear();
			ull nodes=dfs(i);
			if(foundcut.size()<=1)
			{
				cnt++;
				ways=ways*nodes;
			}
		}
	}
	if(!tcut)
	{
		cnt=2;
		ways=(n*(n-1))/2;
	}
	printf("%llu %llu\n",cnt,ways);
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

