//Author - Soumik Roy
//Date & Time - September 23, 2020 10:11 PM
//Problem name - 1040 - Donation
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1040
//Time limit - 2000 ms
//Memory Limit - 32 MB    
//Parsed with ai-virtual-assistant https://github.com/Saurav-Paul/AI-virtual-assistant-python

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
vector<vector<pii> > graph;
int n;
int prim()
{
	bool mark[n+1]={};
	int total_reached=0,total_cost=0;
	priority_queue<pii,vector< pii >,greater< pii > > pq;
	pq.push(mp(0,0));
	while(!pq.empty())
	{
		int node = pq.top().S;
		int cost = pq.top().F;
		pq.pop();
		if(mark[node])
			continue;
		mark[node] = true;
		total_cost += cost;
		total_reached++;
		for(auto x: graph[node])
		{
			pq.push(mp(x.S,x.F));
		}
	}
	if(total_reached != n) total_cost = -1;
	return total_cost;
}
void solve()
{
	cin>>n;
	graph = vector<vector<pii>> (n+1);
	int total=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int cost;
			cin>>cost;
			if(cost)
			{
				graph[i].eb(j,cost);
				graph[j].eb(i,cost);
			}
			total += cost;
		}
	}
	int ans = prim();
	if(ans!=-1)
		cout<<total-ans<<endl;
	else 
		cout<<-1<<endl;
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

