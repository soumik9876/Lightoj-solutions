//Author - Soumik Roy
//Date & Time - August 25, 2020 7:46 PM
//Problem name - 1281 - New Traffic System
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1281
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
int n,m,k,d;
vector< vector<pii> > graph1,graph2;
int dijkstra()
{
	int dist[n+1][d+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=d;j++)
			dist[i][j]=INF;
	}
	dist[0][0]=0;
	priority_queue< pair<int,pii>,vector<pair<int,pii>>,greater< pair<int,pii>>> pq;
	pq.push(mp(0,mp(0,0)));
	while(!pq.empty())
	{
		int dis=pq.top().F;
		pii node=pq.top().S;
		pq.pop();
		if(dist[node.F][node.S]!=dis)
			continue;
		for(auto x: graph1[node.F])
		{
			ll dist1=dis+x.S;
			if(dist1<dist[x.F][node.S])
			{
				dist[x.F][node.S]=dist1;
				pq.push(mp(dist1,mp(x.F,node.S)));
			}
		}
		for(auto x: graph2[node.F])
		{
			ll dist1;
			
			if(node.S<d)
			{
				dist1=dis+x.S;
				if(dist1<dist[x.F][node.S+1])
				{
					dist[x.F][node.S+1]=dist1;
					pq.push(mp(dist1,mp(x.F,node.S+1)));
				}
			}
		}		
	}
	int ans=INF;
	for(int i=0;i<=d;i++)
		ans=min(ans,dist[n-1][i]);
	return ans;
}
void solve()
{
	int u,v,w;
	scanf("%d %d %d %d",&n,&m,&k,&d);
	graph1=vector<vector<pii>> (n+1);
	graph2=vector<vector<pii> > (n+1);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		graph1[u].eb(v,w);
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		graph2[u].eb(v,w);
	}
	int ans=dijkstra();
	if(ans!=INF)
		printf("%d\n",ans);
	else
		printf("Impossible\n");
}
int main()
{
    //KAMEHAMEHA
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case %d: ",cn);
		solve();
	}
    return 0;
}

