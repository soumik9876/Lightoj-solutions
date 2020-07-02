//Author - Soumik Roy
//Date & Time - June 30, 2020 8:06 PM
//Problem name - 1234 - Harmonic Number
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1234
//Time limit - 3000 sec
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
const ll limit=1e8+10;
const ll save=2e6+10;
double pref[save+10];
void store()
{
	double sum=0;
	for(int i=1;i<=limit;i++)
	{
		sum=sum+(1.0/i);
		if(i%50==0)
			pref[i/50]=sum;
	}
}
void solve(int cn)
{
	
	int n;
	double ans;
	scanf("%d",&n);
	int start=n/50;
	ans=pref[start];
	start=n-(n%50)+1;

	while (start <= n)
	{
		ans=ans+(1.0/start);
		start++;
	}
	printf("Case %d: %.9lf\n",cn,ans);
	
}
int main()
{
    //KAMEHAMEHA
	store();
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		solve(cn);
	}
    return 0;
}

