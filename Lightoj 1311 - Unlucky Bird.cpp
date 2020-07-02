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
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
	int t;
	cin>>t;
	for(int cn=1;cn<=t;cn++)
	{
		double v1,v2,v3,a1,a2;
		cin>>v1>>v2>>v3>>a1>>a2;
		double t1=v1/a1,t2=v2/a2;
		double s1=(v1*t1)-(.5*a1*t1*t1),s2=(v2*t2)-(.5*a2*t2*t2);
		s1=s1+s2;
		cout<<"Case "<<cn<<": ";
		s2=v3*max(t1,t2);
		cout<<fixed<<setprecision(7)<<s1<<" "<<s2<<endl;
	}
    return 0;
}

