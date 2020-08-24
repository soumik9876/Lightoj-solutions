//Author - Soumik Roy
//Date & Time - August 24, 2020 1:25 PM
//Problem name - 1099 - Not the Best
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1099
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
struct node{
	int s1,s2,smallest;
};
const int INF=1e9;
int dir[]={0,1,0,-1,1,0,-1,0};
int n,r;
vector<vector< pii > > graph;
int dijsktra()
{
	bool marked[n+1]={};
	vector<node> d(n+1);
	for(int i=2;i<=n;i++)
	{
		d[i].s1=INF;
		d[i].s2=INF;
		d[i].smallest=INF;
	}
	d[1].s1=0,d[1].s2=INF,d[1].smallest=INF;
	for(int i=1;i<=n;i++)
	{
		for(auto x: graph[i])
		{
			d[i].smallest=min(x.S,d[i].smallest);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int vertice=-1;
		for(int j=1;j<=n;j++)
		{
			if(!marked[j]  )
			{
				if(vertice==-1)
					vertice=j;
				else if(d[j].s1<d[vertice].s1)
					vertice=j;
			}
		}
		if(d[vertice].s1==INF)
			break;
		marked[vertice]=true;
		for(auto x: graph[vertice])
		{
			if(d[x.F].s1>d[vertice].s1+x.S)
			{
				d[x.F].smallest=min(d[x.F].smallest,d[vertice].smallest);
				d[x.F].s2=min({d[x.F].s1,d[vertice].s1+x.S+2*d[x.F].smallest,d[vertice].s2+x.S});
				d[x.F].s1=d[vertice].s1+x.S;
			}
			else if(d[vertice].s1+x.S<d[x.F].s2 && d[vertice].s1+x.S>d[x.F].s1)
				d[x.F].s2=d[vertice].s1+x.S;
			
		}
	}
	
	return d[n].s2;
}
void solve()
{
	scanf("%d %d",&n,&r);
	graph.clear();
	graph=vector<vector < pii > > (n+1);
	for (int i = 0; i < r; i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		graph[u].eb(v,w);
		graph[v].eb(u,w);
	}
	int ans=dijsktra();
	printf("%d\n",ans);
}
int main()
{
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		cout<<"Case "<<cn<<": ";
		solve();
	}
    return 0;
}

