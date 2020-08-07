//Author - Soumik Roy
//Date & Time - August 07, 2020 5:38 PM
//Problem name - 1046 - Rider
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1046
//Time limit - 1000 ms
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
int dir[]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
int cost[12][12];
int visitcnt[12][12];
int n,m;
string s[12];

void bfs(pii start)
{
	queue< pair<pii, int> > q;
	q.push(mp(start,0));
	bool visited[n+1][m+1]={};
	visited[start.F][start.S]=true;
	while(!q.empty())
	{
		pii node=q.front().F;
		int dist=q.front().S;
		cost[node.F][node.S]+=ceil((double)dist/(s[start.F][start.S]-'0'));
		visitcnt[node.F][node.S]++;
		q.pop();
		for(int i=0;i<16;i+=2)
		{
			if(!visited[node.F+dir[i]][node.S+dir[i+1]] && node.F+dir[i]<n && node.F+dir[i]>=0 && node.S+dir[i+1]<m && node.S+dir[i+1]>=0)
			{
				q.push(mp(mp(node.F+dir[i],node.S+dir[i+1]),dist+1));
				visited[node.F+dir[i]][node.S+dir[i+1]]=true;
			}
		}
	}
}

void solve()
{
	cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		cin>>s[i];
	}
	memset(cost,0,sizeof(cost));
	memset(visitcnt,0,sizeof(visitcnt));
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]!='.')
			{
				bfs(mp(i,j));
				cnt++;
			}
		}
	}

	int mn=-1;
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(visitcnt[i][j]==cnt )
			{
				if(mn==-1) mn=cost[i][j];
				mn=min(mn,cost[i][j]);
			}
		}
	}
	cout<<mn<<endl;
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

