#include<bits/stdc++.h>
#define nl '\n'
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll long long int
#define loop(a,b)           for(int i=a;i<=b;++i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);

using namespace std;
int x=1;
void FAST_IO();
ll btd(ll b);
int main()
{
    //_time_
   //FAST_IO();
   int i=1;
    sv()
    {
        ll a,b,c,d,abin,bbin,cbin,dbin;
        char ch;
        cin>>a>>ch>>b>>ch>>c>>ch>>d;
        cin>>abin>>ch>>bbin>>ch>>cbin>>ch>>dbin;
        ll A=btd(abin);
        ll B=btd(bbin);
        ll C=btd(cbin);
        ll D=btd(dbin);
        if(A==a && B==b && C==c && D==d)
            cout<<"Case "<<i<<": "<<"Yes\n";
        else
            cout<<"Case "<<i<<": "<<"No\n";
        i++;
    }



   // show
    return 0;
}
void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
#ifndef _offline
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


ll btd(ll b)
{
    int d=0;
    int i=0;
    while(b!=0)
    {
        d+=(b%10)*(pow(2,i));
        b/=10;
        i++;
    }
    return d;
}

