#include<bits/stdc++.h>
#define endl '\n'
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll                    long long int
#define loop(a,b)             for(int i=a;i<=b;++i)
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
string grid[510];
ll visited[510][510];
ll k,m,q;
ll memo[510][510];
void bfs(ll a,ll b,ll z);
ll ans[1010];
void FAST_IO();
int main()
{
    //_time_
   //FAST_IO();
   int cnt = 1;
    tcase()
    {
        ll x,y;
        memset(visited,0,sizeof(visited));
        memset(memo, -1, sizeof(memo));
        cin>>m>>k>>q;
        for(ll i=0;i<m;i++)
        {
            grid[i].clear();
        }
        for(ll i=0;i<m;i++)
            cin>>grid[i];
        cout << "Case " <<cnt++ << ":"<< endl;
        for(ll i=1;i<=q;i++)
        {
            cin>>x>>y;
//            if(memo[x-1][y-1] != -1)
//            {
//                for(ll i=0;i<m;i++)
//                {
//                    for(ll j=0;j<k;j++)
//                        cout<<memo[i][j]<< " ";
//                    cout<<endl;
//                }
//                cout<<memo[x-1][y-1]<<endl;
//            }
            if(memo[x-1][y-1]!=-1)
            {
                cout<<ans[memo[x-1][y-1]]<<endl;
            }
            else
            {
                ans[i]=0;
            //memset(visited,0,sizeof(visited));
            bfs(x-1,y-1,i);
            cout<<ans[i]<<endl;
            }
        }
    }


   // show
    return 0;
}
void bfs(ll a,ll b,ll z)
{
    //cout<<a<< " "<<b<< " "<<k<< " "<<m<<endl;
    if(a < 0 || a > m-1 || b < 0  || b > k-1) return;
    if(visited[a][b] || grid[a][b] == '#')
        return;
    visited[a][b]=true;

    if(grid[a][b]=='C')
        ans[z]++;

    //cout<<a<< " "<<b<<" "<<ans<<" " <<grid[a][b+1]<<endl;
    bfs(a,b+1,z);
    bfs(a-1,b,z);
    bfs(a,b-1,z);
    bfs(a+1,b,z);
    memo[a][b] = z;
//    if(b+1<=n-1)
//    {
//        if(grid[a][b+1]=='C' || grid[a][b+1]=='.')
//        {
//            bfs(a,b+1);
//        }
//    }
//    //cout<<a<< " "<<b<< " "<<ans<<endl;
//    if(a-1>=0)
//    {
//        if(grid[a-1][b]=='C' || grid[a-1][b]=='.')
//        {
//            bfs(a-1,b);
//        }
//    }
//    if(b-1>=0)
//    {
//        if(grid[a][b-1]=='C' || grid[a][b-1]=='.')
//        {
//            bfs(a,b-1);
//        }
//    }
//    if(a+1<=m-1)
//    {
//        if(grid[a+1][b]=='C' || grid[a+1][b]=='.')
//        {
//            bfs(a+1,b);
//
//        }
//    }
}
void FAST_IO()
{
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    //cout.tie(0);
//    //cout.setf(ios::fixed);
//    //cout.precision(20);
//#ifndef _offline
//    //freopen("input.txt", "r", stdin);
//    //freopen("output.txt", "w", stdout);
//#endif
}

