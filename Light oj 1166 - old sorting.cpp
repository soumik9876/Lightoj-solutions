
// Problem : 1166 - Old Sorting
// Contest : LightOJ
// URL : http://lightoj.com/volume_showproblem.php?problem=1166
// Memory Limit : 32.000000 MB 
// Time Limit : 2000.000000 milisec 

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
void solve(int cn)
{
	int n,cnt=0;
	vi a;
	cin>>n;
	vi pos(n+1),num(n+1);
	for(int i=1,temp;i<=n;i++)
	{
		cin>>temp;
		pos[temp]=i;
		num[i]=temp;
		
	}
	
	for(int i=1;i<=n;i++)
	{
		if(pos[i]!=i)
		{
			pos[num[i]]=pos[i];
			num[pos[i]]=num[i];
			num[i]=i;
			pos[i]=i;
			cnt++;
		}
	}
	cout<<"Case "<<cn<<": "<<cnt<<endl;
}
int main()
{
    KAMEHAMEHA
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		solve(i);
	}
    return 0;
}

