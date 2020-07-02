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
    int t,n,k;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        cin>>n>>k;
        n++;
        vi a;
        for(int i=0,temp;i<n;i++)
        {
            cin>>temp;
            a.eb(temp);
        }
        int low=1,high=1e7,ans;
        int guess=high-((high-low)>>1);
        int cnt=0,total=0;
        while(low<=high)
        {
            cnt=0,total=0;
            guess=low+((high-low)>>1);
            bool check=true;
            //cout<<high<< " "<<low<< " "<<guess<<endl;
            for(int i=0;i<n;i++)
            {
                if(a[i]+total<=guess)
                    total+=a[i];
                else
                {
                    total=a[i];
                    cnt++;
                }
                if(i==n-1)
                    cnt++;
                if(cnt>k+1 || guess<a[i])
                {
                    check=false;
                    break;
                }
            }
            if(check)
            {
                high=guess-1;
                ans=guess;
            }
            else
                low=guess+1;
        }
        total=0,cnt=0;

        cout<<"Case "<<x<<": "<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]+total<=ans && k-cnt<n-i)
                total+=a[i];
            else
            {
                cout<<total<<endl;
                total=a[i];
                cnt++;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}

