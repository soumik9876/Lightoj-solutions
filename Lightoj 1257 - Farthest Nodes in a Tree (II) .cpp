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
vector <pll>  graph[30010];
ll n,u,v,r,mx;
ll farthest(ll n);
ll bfs(ll start,ll dist[]);
void FAST_IO();
int main()
{
    //_time_
   //FAST_IO();
   ll c=1;
    tcase()
    {

        cin>>n;
        for(ll i=0;i<n;i++)
            graph[i].clear();
        for(ll i=0;i<n-1;i++)
        {
            cin>>u>>v>>r;
            graph[u].pb(make_pair(v,r));
            graph[v].pb(make_pair(u,r));
        }
        ll dist1[30010],dist2[30010];
        memset(dist1,-1,sizeof(dist1));
        memset(dist2,-1,sizeof(dist2));
        ll n1=bfs(0,dist1);
        memset(dist1,-1,sizeof(dist1));
        ll n2=bfs(n1,dist1);
        bfs(n2,dist2);
        cout<<"Case "<<c++<<":"<<endl;
        for(ll i=0;i<n;i++)
            cout<<max(dist1[i],dist2[i])<<endl;

        //cout<<bfs(0,dist)<<endl;
    }


   // show
    return 0;
}
ll bfs(ll start,ll dist[]) {

    queue<ll> q;
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
//#ifndef _offline
//    //freopen("input.txt", "r", stdin);
//    //freopen("output.txt", "w", stdout);
//#endif
}

