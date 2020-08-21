//Author - Soumik Roy
//Date & Time - August 21, 2020 2:33 PM
//Problem name - 1357 - Corrupted Friendship
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1357
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
vector<vi> tree;
ll ans=0;
ll dfs(int node,int prev)
{
	ll sumofsquares=0,squareofsum=0,nodes=0;
	for(auto x: tree[node])
	{
		if(x==prev)
			continue;
		ll thisbranch=dfs(x,node);
		nodes+=thisbranch;
		sumofsquares+=(thisbranch*thisbranch);
		squareofsum+=thisbranch;
	}
	squareofsum*=squareofsum;
	ll temp=(squareofsum-sumofsquares)/2;
	ans=ans+temp;
	return nodes+1;
}
void solve()
{
	ll n;
	scanf("%lld",&n);
	tree=vector<vi> (n+1);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		tree[u].eb(v);
		tree[v].eb(u);
	}
	ans=0;
	ll invitations=dfs(1,0)-1;
	printf("%lld %lld\n",invitations,ans);
}
int main()
{
    //KAMEHAMEHA
	int t=1;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case %d: ",cn);
		solve();
	}
    return 0;
}

