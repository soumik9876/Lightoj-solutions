#include<bits/stdc++.h>
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll                    long long int
#define loop(a,b)             for(int i=a;i<=b;++i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
#define eb                    emplace_back
#define ull                   unsigned long long
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
    for(int i=1;i<=t;i++)
    {
        vi white,black;
        int n,temp,xorsum=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            white.eb(temp);
        }
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            black.eb(temp);
        }
        for(int j=0;j<n;j++)
        {
            xorsum^=(black[j]-white[j]-1);
        }
        cout<<"Case "<<i<<": ";
        if(xorsum>0)
            cout<<"white wins"<<endl;
        else
            cout<<"black wins"<<endl;
    }
    return 0;
}

