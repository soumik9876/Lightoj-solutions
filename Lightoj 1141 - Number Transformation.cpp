#include<bits/stdc++.h>
#define endl '\n'
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll                  long long int
#define ull                 unsigned long long
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
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);

using namespace std;
bool isprime[200];
vll factors[110];
void FAST_IO();
void sieve();
int main()
{
    //_time_
   //FAST_IO();
    sieve();
//    for(ll i=0;i<100;i++)
//        cout<<isprime[i]<< " ";
    for(ll i=1;i<=110;i++)
    {
        for(ll j=2;j*j<=i;j++)
        {
            if(j*j==i && isprime[j]==false)
                factors[i].pb(j);
            else if(i%j==0)
            {
                if(!isprime[j])
                    factors[i].pb(j);
                if(!isprime[i/j])
                    factors[i].pb(i/j);
            }

        }
    }
    for(ll i=1;i<10;i++)
    {
        for(ll j=0;j<factors[i].size();j++)
        {
            cout<<i<< " "<<factors[i][j]<<endl;
        }
    }
    tcase()
    {
        ll s,t;
        cin>>s>>t;

    }
   // show
    return 0;
}
void sieve()
{
    isprime[0]=true;
    isprime[1]=true;
    for(ll i=4;i<=110;i+=2)
        isprime[i]=true;
    for(int i=3;i*i<=110;i++)
    {
        if(!isprime[i])
        {
            for(int j=i*i;j<=110;j+=i)
            {
                isprime[j]=true;
            }
        }
    }
}


void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
#ifndef _offline
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}

