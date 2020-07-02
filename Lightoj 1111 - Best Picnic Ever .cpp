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
vll people,graph[1010];
ll visitcnt[1010];
bool visited[1010];
void bfs(ll r);
void FAST_IO();
int main()
{
    //_time_
   //FAST_IO();
    int c = 1;
    tcase()
    {

        ll k,n,m,u,v;
        memset(visitcnt,0,sizeof(visitcnt));
        people.clear();
        cin>>k>>n>>m;
        for(ll i=0;i<n;i++)
            graph[i].clear();
        for(ll i=0;i<k;i++)
        {
            ll temp;
            cin>>temp;
            people.pb(temp);
        }
        for(ll i=0;i<m;i++)
        {
            cin>>u>>v;
            graph[u].pb(v);
        }
        for(ll i=0;i<k;i++)
        {
            memset(visited,0,sizeof(visited));
            bfs(people[i]);
        }
        int ans = 0;
        for(ll i=1; i <= n; i++) {

            //cout << visitcnt[i]<<endl;
            if(visitcnt[i] == k) {

               ans++;
            }
        }
        cout <<"Case " << c++ << ": " << ans << endl;
    }


   // show
    return 0;
}
void bfs(ll r)
{
    queue<ll> q;
    visited[r]=true;
    q.push(r);
    visitcnt[r]++;
    while(!q.empty())
    {
        ll u=q.front();
       // cout<<"U->"<<u<<endl;
        q.pop();
        for(ll i=0;i<graph[u].size();i++)
        {
            if(!visited[graph[u][i]])
            {
                visited[graph[u][i]]=true;
                visitcnt[graph[u][i]]++;
                q.push(graph[u][i]);
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

