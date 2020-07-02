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
    for(int i=1;i<=t;i++)
    {
        int n;
        vi a;
        cin>>n;
        for(int j=0,temp;j<n;j++)
        {
            cin>>temp;
            a.eb(temp);
        }
        sort(all(a));
//        for(int k=0;k<n;k++)
//        {
//            for(int j=k;j<n;j++)
//            {
//                if(j==k)
//                    continue;
//                sides.eb(a[k]+a[j]);
//            }
//        }
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {

                int upper=lower_bound(all(a),a[j]+a[k])-a.begin();
                //cout<<a[j]+a[k]<<" "<<upper<<" "<<upper-k<<endl;
                cnt+=max(0,upper-k-1);
            }
        }
        cout<<"Case "<<i<<": "<<cnt<<endl;
    }
    return 0;
}


