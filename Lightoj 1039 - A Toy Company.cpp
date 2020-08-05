//Author - Soumik Roy
//Date & Time - August 05, 2020 6:05 PM
//Problem name - 1039 - A Toy Company
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1039
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
#define psl 				  pair<string ,int> 
using namespace std;
void solve(int cn)
{
	string s,t;
	cin>>s>>t;
	int n;
	cin>>n;
	bool check[n+1][3][27]={};
	for(int i=0;i<n;i++)
	{
		string a,b,c;
		cin>>a>>b>>c;
		for(auto x : a)
		{
			check[i][0][x-'a']=true;
		}
		for(auto x: b)
			check[i][1][x-'a']=true;
		for(auto x: c)
			check[i][2][x-'a']=true;
	}
	unordered_map< string, int > visited;
	queue< psl > q;
	q.push(mp(s,0));
	visited[s]=true;
	int ans=-1;
	while (!q.empty())
	{
		psl cur=q.front();
		q.pop();
		bool valid=true;
		for(int i=0;i<n;i++)
		{
			if(check[i][0][cur.F[0]-'a'] && check[i][1][cur.F[1]-'a'] && check[i][2][cur.F[2]-'a'])
			{
				valid=false;
				break;
			}
		}
		if(cur.F==t)
		{
			if(valid)
			{
				ans=cur.S;
			}
			break;
		}
		if(!valid)
			continue;
		for(int i=0;i<3;i++)
		{
			string pathaw=cur.F;
			if(pathaw[i]=='z')
				pathaw[i]='a';
			else
				pathaw[i]++;
			if(!visited[pathaw])
			{
				q.push(mp(pathaw,cur.S+1));
				visited[pathaw]=true;
			}
			pathaw=cur.F;
			if(pathaw[i]=='a')
				pathaw[i]='z';
			else
				pathaw[i]--;
			if(!visited[pathaw])
			{
				q.push(mp(pathaw,cur.S+1));
				visited[pathaw]=true;
			}
		}
	}
	cout<<"Case "<<cn<<": "<<ans<<endl;
}
int main()
{
    KAMEHAMEHA
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		solve(cn);
	}
    return 0;
}

