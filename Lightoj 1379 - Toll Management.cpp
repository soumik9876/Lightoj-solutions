//Author - Soumik Roy
//Date & Time - August 27, 2020 4:23 PM
//Problem name - 1379 - Toll Management
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1379
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
const int INF=1e9;
int n,m,s,t,p;

void dijkstra(vector<vector< pii > > &g,vector<int> &dist)
{
	 for(int i=1;i<=n;i++)
	 	dist[i]=INF;
	dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push(mp(0,s));
	while(!pq.empty())
	{
		int node=pq.top().S;
		int dis=pq.top().F;
		pq.pop();
		if(dist[node]!=dis)
			continue;
		for(auto x: g[node])
		{
			if(dist[x.F]>dis+x.S)
			{
				dist[x.F]=dis+x.S;
				pq.push(mp(dis+x.S,x.F));
			}
		}
	}
}
void solve()
{
	scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
	vector<vector<pii> > graph(n+1),rgraph(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		graph[u].eb(v,c);
		rgraph[v].eb(u,c);
	}
	vi dist1(n+1),dist2(n+1);
	dijkstra(graph,dist1);
	swap(s,t);
	dijkstra(rgraph,dist2);
	int ans=-1;
	
	for(int i=1;i<=n;i++)
	{
		for(auto x: graph[i])
		{
			if(dist1[i]+x.S+dist2[x.F]<=p && x.S>ans)
				ans=x.S;
		}
	}
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

