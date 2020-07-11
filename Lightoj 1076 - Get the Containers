//Author - Soumik Roy
//Date & Time - July 03, 2020 10:59 PM
//Problem name - 1076 - Get the Containers
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1076
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
	int n,m,mx=0;
	vi c;
	cin>>n>>m;
	for (int i = 0,temp; i < n; i++)
	{
		cin>>temp;
		c.eb(temp);
		mx=max(temp,mx);
	}
	
	ll high=1e9,low=mx,mid,ans=INT_MAX;
    while (low<=high)
    {
        mid=low+((high-low)/2);
        int containers=1,milk=0;
        for(int i=0;i<n;i++)
        {
            if(milk+c[i]>mid)
            {
                containers++;
                milk=0;
            }
            milk+=c[i];
        }
        if(containers>m)
        {
            low=mid+1;
        }
        else if(containers<m)
            high=mid-1;
        else
        {
            ans=min(ans,mid);
            high=mid-1;
        }
        
    }

    cout<<"Case "<<cn<<": ";
    if(ans==INT_MAX)
        cout<<mx<<endl;
    else
    {
        cout<<ans<<endl;
    }
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

