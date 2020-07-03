//Author - Soumik Roy
//Date & Time - July 03, 2020 7:55 PM
//Problem name - 1016 - Brush (II)
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1016
//Time limit - 2000 sec
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
void solve(int cn)
{
	ll n,w;
	cin>>n>>w;
	vll a;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a.eb(y);
	}
	sort(all(a));
	ll total=1,start=0;

	for(int i=1;i<n;i++)
	{
		//cout<<start<<" "<<total<<endl;
		if(a[i]-a[start]>w)
		{
			total++;
			start=i;
		}
	}
	cout<<"Case "<<cn<<": "<<total<<endl;
}
int main()
{
    KAMEHAMEHA
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		//cout<<cn<<" "<<t<<endl;
		solve(cn);
	}
    return 0;
}

