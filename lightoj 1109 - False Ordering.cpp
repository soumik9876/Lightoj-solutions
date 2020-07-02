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
bool modsort(const pii &p1,const pii &p2)
{
    if(p1.F<p2.F)
        return true;
    if(p1.F==p2.F )
        return (p1.S>p2.S);
    return false;
}
vector< pii > divcnt(1001);
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    for(int i=1;i<=1000;i++)
    {
        for(int j=i;j<=1000;j+=i)
        {
            divcnt[j].F++;
            divcnt[j].S=j;
        }
    }
    sort(all(divcnt),modsort);

    int q;
    cin>>q;
    for(int cn=1;cn<=q;cn++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<cn<<": "<<divcnt[n].S<<endl;
    }
    return 0;
}

