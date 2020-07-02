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
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
#define eb                    emplace_back
#define ull                   unsigned long long
#define KAMEHAMEHA            ios_base::sync_with_stdio(0);
#define RASENGAN              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int dp[211][110],n;
int solve(int row,int col,vector< vi > &diamond )
{

    if(row>=0 && row<2*n-1)
    {
        if(dp[row][col]!=-1)
            return dp[row][col];
        if(row==2*n-2) return diamond[row][col];
        int value=-INT_MAX;
        if(row<n-1)
        {
            value=max(value,solve(row+1,col,diamond)+diamond[row][col]);
            value=max(value,solve(row+1,col+1,diamond)+diamond[row][col]);
        }
        else
        {
            if(col==0)
                value=max(value,solve(row+1,col,diamond)+diamond[row][col]);
            else if(col==(2*n-2)-row)
                value=max(value,solve(row+1,col-1,diamond)+diamond[row][col]);
            else
            {
                value=max(value,solve(row+1,col,diamond)+diamond[row][col]);
                value=max(value,solve(row+1,col-1,diamond)+diamond[row][col]);
            }
        }
       // cout<<row<< " "<<col<<" "<<value<<endl;
        return dp[row][col]=value;
    }
    return 0;
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n;
        vector< vi > diamond(2*n+5);
        memset(dp,-1,sizeof(dp));


        for(int i=0,temp;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cin>>temp;
                diamond[i].eb(temp);
            }
        }


        for(int i=0,temp;i<n-1;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                cin>>temp;
                diamond[i+n].eb(temp);
            }
        }
//        for(int i=0;i<2*n-1;i++)
//        {
//            for(auto j:diamond[i])
//                cout<<j<< " ";
//            cout<<endl;
//        }
        cout<<"Case "<<tc<<": "<<solve(0,0,diamond)<<endl;

    }
    return 0;
}


