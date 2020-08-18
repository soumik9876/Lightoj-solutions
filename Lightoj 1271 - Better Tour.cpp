//Author - Soumik Roy
//Date & Time - August 18, 2020 4:36 PM
//Problem name - 1271 - Better Tour
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1271
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
const int lim=5e4+10;
int n,start,ending;
vector<vi> graph(lim);
bool visited[lim];
vi previous(lim);
void bfs(int node)
{
	queue< int > q;
	previous[node]=-1;
	q.push(node);
	visited[node]=true;
	while(!q.empty())
	{
		int ver=q.front();
		q.pop();
		sort(all(graph[ver]));
		for(auto x : graph[ver])
		{
			if(visited[x])
				continue;
			visited[x]=true;
			previous[x]=ver;
			q.push(x);
			if(x==ending)
				return;
		}
	}
}
void solve()
{
	scanf("%d",&n);
	int u,v,mx=0;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		graph[a[i]].clear();
		visited[a[i]]=false;
	}
	
	start=a[0],ending=a[n-1];
	for(int i=0;i<n-1;i++)
	{
		graph[a[i]].eb(a[i+1]);
		graph[a[i+1]].eb(a[i]);
	}
	
	bfs(start);
	vi ans;
	int node=ending;
	while(previous[node]!=-1)
	{
		ans.eb(node);
		node=previous[node];
	}
	ans.eb(start);
	int sz=ans.size();
	for(int i=sz-1;i >= 0;i--)
	{
		printf("%d",ans[i]);
		if(i>0)
			printf(" ");
	}
	cout<<endl;
}
int main()
{
    //KAMEHAMEHA
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case %d:\n",cn);
		solve();
	}
    return 0;
}

