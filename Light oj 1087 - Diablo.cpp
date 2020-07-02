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
int main()
{
    //KAMEHAMEHA
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,q;
		scanf("%d %d",&n,&q);
		vi a;
		a.eb(0);
		for(int i=0,temp;i<n;i++)
		{
			scanf("%d",&temp);
			a.eb(temp);
		}
		multiset<int> deleted;
		printf("Case %d:\n",i);
		while(q--)
		{
			char c;
			int k;
			scanf(" %c %d",&c,&k);
			if(c=='c')
			{	
				if(k>=a.size())
					printf("none\n");
				else
				{
					
					printf("%d\n",a[k]);
					a.erase(a.begin()+k);
				}
			}
			else
				a.eb(k);
		}
	}
    return 0;
}

