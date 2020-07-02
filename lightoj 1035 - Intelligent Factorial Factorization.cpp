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
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int spf[110];
int factors[110][110];
void sieve()
{
    for(int i=2;i<101;i++)
        spf[i]=i;
    for(int i=2;i<=100;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=100;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}
void factorization()
{
    for(int i=2;i<=100;i++)
    {
        int num=i;
        while(num!=1)
        {
            factors[i][spf[num]]++;
            num/=spf[num];
        }
    }
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    sieve();
    factorization();
    for(int i=2;i<=100;i++)
    {
        for(int j=2;j<=100;j++)
        {
            factors[j][i]+=factors[j-1][i];
        }
    }
//    for(int i=1;i<=10;i++)
//    {
//        for(int j=1;j<=10;j++)
//            cout<<factors[i][j]<< " ";
//        cout<<endl;
//    }
    int t;
    cin>>t;
    for(int cn=1;cn<=t;cn++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<cn<<": "<<n<<" = ";
        int cnt=0;
        for(int i=2;i<=n;i++)
        {
            if(factors[n][i])
            {
                if(cnt>0)
                    cout<<" * ";
                cout<<i<< " ("<<factors[n][i]<< ")";
                cnt++;
            }
        }
        cout<<endl;
    }
    return 0;
}


