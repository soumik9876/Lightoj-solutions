//Author - Soumik Roy
//Date & Time - August 23, 2020 4:24 PM
//Problem name - 1377 - Blade and Sword
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1377
//Time limit - 3000 ms
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
string grid[210];
int n,m;
int bfs()
{
    pii p;
    vector< pii > star;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]=='P')
				p=mp(i,j);
			if(grid[i][j]=='*')
				star.eb(i,j);
		}
	}
    int visitedstar=0,starcnt=star.size(),ans=-1,pushedstar=0;
	queue< pair<pii,int> > q;
	bool visited[210][210]={};
	q.push(mp(p,0));
	visited[p.F][p.S]=true;
	while(!q.empty())
	{
		pii node=q.front().F;
		int dist=q.front().S;
		q.pop();
		for(int i=0;i<8;i+=2)
		{
            if(grid[node.F][node.S]=='*') break;
			pii next=mp(node.F+dir[i],node.S+dir[i+1]);
			
			if(visited[next.F][next.S])
				continue;
			if(grid[next.F][next.S]=='D')
			{
				if(ans==-1) ans=dist+1;
				ans=min(ans,dist+1);
                continue;
			}
			if(grid[next.F][next.S]=='.')
			{
				q.push(mp(next,dist+1));
                visited[next.F][next.S]=true;
			}
			if(grid[next.F][next.S]=='*' && starcnt>1)
			{
                pushedstar++;
                if(pushedstar>1)
                    break;
                q.push(mp(next,dist+1));
                visited[next.F][next.S]=true;
			}
			
		}
        if(grid[node.F][node.S]=='*')
        {
            if(!visitedstar)
            {
                for(auto x: star)
                {
                    if(visited[x.F][x.S])
                        continue;
                    q.push(mp(mp(x.F,x.S),dist+1));
                    visited[x.F][x.S]=true;
                }
                visitedstar=1;
                dist+=2;
                if(pushedstar>1)
                    dist--;
            }

            for(int i=0;i<8;i+=2)
            {
                pii next=mp(node.F+dir[i],node.S+dir[i+1]);
                if(visited[next.F][next.S])
                    continue;
                if(grid[next.F][next.S]=='D')
                {
                    if(ans==-1) ans=dist+1;
                    ans=min(ans,dist+1);
                    continue;
                }
                if(grid[next.F][next.S]=='.')
                {
                    q.push(mp(next,dist+1));
                    visited[next.F][next.S]=true;
                }
            }
        }
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>grid[i];	
	int dist=bfs();
	
	if(dist!=-1)
		cout<<dist<<endl;
	else
		cout<<"impossible"<<endl;
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

