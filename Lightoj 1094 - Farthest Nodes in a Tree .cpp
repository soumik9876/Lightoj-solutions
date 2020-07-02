#include<bits/stdc++.h>
#define endl '\n'
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll long long int
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
#define eb                    emplace_back
using namespace std;
ll dist[30000];
ll n,u,v,d,k, mx = -1;
queue<ll> q;
void FAST_IO();
vector< pll > graph[30000];
ll bfs(ll start);
int main()
{
    //_time_
   //FAST_IO();
    int c = 1;
    tcase()
    {
        cin>>n;
        memset(dist, -1, sizeof(dist));
        for(ll i = 0; i < 30000; i++) {

            graph[i].clear();
        }

        for(ll i=0;i<n-1;i++)
        {
            cin>>u>>v>>d;
            graph[u].push_back(make_pair(v, d));
            graph[v].push_back(make_pair(u, d));
        }

        ll s = bfs(0);
        //cout << s << endl;
        memset(dist, -1, sizeof(dist));
        ll l = bfs(s);
        //cout << l << endl;
        cout<<"Case "<<c++<<": "<<mx<<endl;

    }


   // show
    return 0;
}

ll bfs(ll start) {

    dist[start] = 0;
    q.push(start);
    ll re = 0;

    mx = -1;
    while(!q.empty()) {

        ll f = q.front();
        q.pop();

        for(ll i = 0; i < graph[f].size(); i++) {

            //cout << "node " << f << " " << graph[f][i].first << endl;
            if(dist[graph[f][i].first] == -1) {

                q.push(graph[f][i].first);
                dist[graph[f][i].first] = dist[f] + graph[f][i].second;
                //cout << "distance " << dist[graph[f][i].first] << endl;
                if(mx < dist[graph[f][i].first]) {

                    mx = dist[graph[f][i].first];
                    re = graph[f][i].first;
                }


            }

        }

    }
    return re;
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

