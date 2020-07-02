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
#define sz  1000000
using namespace std;

int pfcnt(int n,int prime)
{
    int cnt=0;
    while(n%prime==0)
    {
        cnt++;
        n/=prime;
    }
    return cnt;
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    vi twos(sz+10),fives(sz+10);
    twos[0]=0,fives[0]=0;
    for(int i=1;i<=sz;i++)
    {
        twos[i]=pfcnt(i,2)+twos[i-1];
        fives[i]=pfcnt(i,5)+fives[i-1];
    }
    for(int cn=1;cn<=t;cn++)
    {
        int n,r,p,q,two=0,five=0;
        cin>>n>>r>>p>>q;

        two=(twos[n]-twos[n-r])-twos[r]+(q*(twos[p]-twos[p-1]));
        five=(fives[n]-fives[n-r])-fives[r]+(q*(fives[p]-fives[p-1]));

        cout<<"Case "<<cn<<": "<<min(two,five)<<endl;
    }
    return 0;
}


