//Author - Soumik Roy
//Date & Time - August 20, 2020 9:40 PM
//Problem name - 1055 - Going Together
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1055
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
#define bug(x)		      cout<<"  [ "#x<<" = "<<x<<" ]"<<endl;
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct allpair{
	pii a[3];
};
int n,dir[]={0,1,0,-1,1,0,-1,0};
string grid[12];
int bfs()
{
	queue< pair<allpair,int> > q;
	allpair temp;
	bool visited[12][12][12][12][12][12]={};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(grid[i][j]=='A') 
				temp.a[0]=mp(i,j);
			if(grid[i][j]=='B')
				temp.a[1]=mp(i,j);
			if(grid[i][j]=='C')
				temp.a[2]=mp(i,j);
		}
	}
	q.push(mp(temp,0));
	visited[temp.a[0].F][temp.a[0].S][temp.a[1].F][temp.a[1].S][temp.a[2].F][temp.a[2].S]=true;
	while(!q.empty())
	{
		allpair nodes=q.front().F;
		int dist=q.front().S;
		q.pop();

		for(int i=0;i<8;i+=2)
		{
			allpair next;
			for(int j=0;j<=2;j++)
			{
				next.a[j]=mp(nodes.a[j].F+dir[i],nodes.a[j].S+dir[i+1]);
				if(next.a[j].F<0 || next.a[j].S<0 || next.a[j].F==n || next.a[j].S==n)
					next.a[j]=nodes.a[j];
				if(grid[next.a[j].F][next.a[j].S]=='#' || next.a[j].F<0 || next.a[j].S<0 || next.a[j].F==n || next.a[j].S==n)
					next.a[j]=nodes.a[j];
			}
			for(int x=0;x<=2;x++)
			{
				for(int j=0;j<=2;j++)
				{
					for(int k=0;k<=2;k++)
					{
						if(j==k) continue;
						if(next.a[j]==next.a[k])
							next.a[j]=nodes.a[j],next.a[k]=nodes.a[k];
					}
				}
			}
			if(visited[next.a[0].F][next.a[0].S][next.a[1].F][next.a[1].S][next.a[2].F][next.a[2].S])
			{
				continue;
			}
			if(grid[next.a[0].F][next.a[0].S]=='X' && grid[next.a[1].F][next.a[1].S]=='X' && grid[next.a[2].F][next.a[2].S]=='X')
			{
				return dist+1;
			}
			visited[next.a[0].F][next.a[0].S][next.a[1].F][next.a[1].S][next.a[2].F][next.a[2].S]=true;
			q.push(mp(next,dist+1));
		}
	}
	return -1;
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>grid[i];
	int ans=bfs();
	if(ans==-1)
		cout<<"trapped"<<endl;
	else
		cout<<ans<<endl;
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

