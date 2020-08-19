//Author - Soumik Roy
//Date & Time - August 19, 2020 2:04 PM
//Problem name - 1175 - Jane and the Frost Giants
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1175
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
int n,m,ans=-1,dir[]={0,1,1,0,0,-1,-1,0};
string s[205];
void bfs()
{
	queue< pair<pii,int> > q;
    pii jane;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='J')
				jane.F=i,jane.S=j;
			if(s[i][j]=='F')
				q.push(mp(mp(i,j),1));
		}
	}
    q.push(mp(jane,1));

	while(!q.empty())
	{
        pii node=q.front().F;
        int dist=q.front().S;
        q.pop();
        for(int i=0;i<8;i+=2)
        {
            pii next=mp(node.F+dir[i],node.S+dir[i+1]);
            if(next.F>=0 && next.F<n && next.S>=0 && next.S<m)
            {
                if(s[node.F][node.S]=='F')
                {
                    if(s[next.F][next.S]=='.')
                    {
                        q.push(mp(next,dist));
                        s[next.F][next.S]='F';
                    }
                }
                else
                {
                    if(s[next.F][next.S]=='.')
                    {
                        if(next.F==0 || next.S==0 || next.F==n-1 || next.S==m-1)
                        {
                            ans=dist+1;
                            return;
                        }
                        q.push(mp(next,dist+1));
                        s[next.F][next.S]='#';
                    }
                }
                
            }
        }

	}
}

void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	ans=-1;
	bfs();
	if(ans!=-1)
		cout<<ans<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
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

