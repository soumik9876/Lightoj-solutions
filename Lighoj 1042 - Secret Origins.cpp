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
        int n,num=0;
        cin>>n;
        string s;
        bool done=false;
        while(n)
        {
            char c=(n%2)+48;
            s+=c;
            n/=2;
        }
        ll sz=s.size(),cnt=0;
        for(int i=0;i<sz;i++)
        {
            if(!done)
            {
                if(s[i]=='1' && (s[i+1]=='0' || i==sz-1))
                {
                    num+=pow(2,i+1)+(pow(2,cnt)-1);
                    done=true;
                }
                else if(s[i]=='1')
                {
                    cnt++;
                }
            }
            else if(s[i]=='1')
            {
                num+=pow(2,i);
            }
        }
        cout<<"Case "<<cn<<": "<<num<<endl;
    }
    return 0;
}

