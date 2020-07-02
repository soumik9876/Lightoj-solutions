
// Problem : 1043 - Triangle Partitioning
// Contest : LightOJ
// URL : http://lightoj.com/volume_showproblem.php?problem=1043
// Memory Limit : 32.000000 MB 
// Time Limit : 500.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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
    KAMEHAMEHA
	int t;
	cin>>t;
	for(int cs=1;cs<=t;cs++)
	{
		double a,b,c,r;
		cin>>a>>b>>c>>r;
		//cout<<fixed<<setprecision(6);
		double tarea=(a+b+c)/2.0;
		tarea=sqrt(tarea*(tarea-a)*(tarea-b)*(tarea-c));
		double h=a,l=0.0,mid;
		for(int i=0;i<=100;i++)
		{
			mid=(h+l)/2;
			
			double rat;
			double d=(mid/a)*b,e=(mid/a)*c;
			double s=(mid+d+e)/2.0;
			double area2=sqrt(s*(s-mid)*(s-d)*(s-e));
			double area3=tarea-area2;
			rat=area2/area3;
			//cout<<fixed<<setprecision(6)<<mid<<" "<<rat<<" "<<h<<" "<<l<<endl;
			
			if(rat>r)
			{
				h=mid;
			}
			else
				l=mid;
		}
		cout<<"Case "<<cs<<": ";
		cout<<fixed<<setprecision(6)<<mid<<endl;
	}
    return 0;
}

