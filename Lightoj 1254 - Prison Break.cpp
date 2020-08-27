//Author - Soumik Roy
//Date & Time - August 27, 2020 7:02 PM
//Problem name - 1254 - Prison Break
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1254
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
int n,m,q,c,s,t;
vi price;
vector<vector<pii>> graph;
int dijkstra()
{
	int cost[n+1][c+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=c;j++)
			cost[i][j]=INF;
	}
	cost[s][0]=0;
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>> > pq;
	pq.push(mp(0,mp(s,0)));
	int cnt=0;
	while(!pq.empty())
	{
		pii node=pq.top().S;
		int cos=pq.top().F;
		pq.pop();
		if(cost[node.F][node.S]!=cos)
			continue;
		
		if(node.S<c)
		{
			if(cost[node.F][node.S+1]>cos+price[node.F])
			{
				cost[node.F][node.S+1]=cos+price[node.F];
				pq.push(mp(cost[node.F][node.S+1],mp(node.F,node.S+1)));
			}
		}
		for(auto x: graph[node.F])
		{
			if(node.S>=x.S)
			{
				if(cost[x.F][node.S-x.S]>cos)
				{
					cost[x.F][node.S-x.S]=cos;
					pq.push(mp(cos,mp(x.F,node.S-x.S)));
				}
			}
		}
	}
	return cost[t][0];
}
void solve()
{
	scanf("%d %d",&n,&m);
	price=vi (n+1);
	graph=vector<vector<pii>> (n+1);
	for(int i=0;i<n;i++)
		scanf("%d",&price[i]);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u].eb(v,w);
		graph[v].eb(u,w);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d %d",&c,&s,&t);
		int ans=dijkstra();
		if(ans==INF)
			printf("impossible\n");
		else
			printf("%d\n",ans);
	}
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

