//Author - Soumik Roy
//Date & Time - August 04, 2020 5:56 PM
//Problem name - 1263 - Equalizing Money
//Problem url - http://lightoj.com/volume_showproblem.php?problem=1263
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

int dsu(int node,vi &parent)
{
	return parent[node] = (parent[node]==node) ? node : dsu(parent[node],parent);
}
void solve(int cn)
{
	int n,m,avg=0;
	scanf("%d %d",&n,&m);
	vi parent(n+1),val(n+1);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&val[i]);
		avg+=val[i];
		parent[i]=i;
	}
	printf("Case %d: ",cn);
	
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		int parent1=dsu(u,parent),parent2=dsu(v,parent);
		if(parent1!=parent2)
			parent[parent2]=parent1;
	}
	if(avg%n)
	{
		printf("No\n");
		return;
	}
	avg/=n;
	unordered_map<int,int> balance;
	for(int i=1;i<=n;i++)
	{
		int par=dsu(i,parent);
		parent[i]=par;
	}
	for (int i = 1; i <= n; i++)
	{
		balance[parent[i]]+=(avg-val[i]);
	}
	
	for(auto x: balance)
	{
		if(x.S)
		{
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}
int main()
{
    //KAMEHAMEHA
	int t=1;
	scanf("%d",&t);
	for(int cn=1;cn<=t;cn++)
	{
		solve(cn);
	}
    return 0;
}

