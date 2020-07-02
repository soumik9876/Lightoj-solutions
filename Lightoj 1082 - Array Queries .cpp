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
void FAST_IO();
void build_tree(vll &tree,vll &a,ll l,ll r,ll pos);
ll query(vll &tree,ll l,ll r,ll L,ll R,ll pos);
int main()
{
    //_time_
    //FAST_IO();
    ll t;
    scanf("%lld",&t);
    for(ll i=1;i<=t;i++)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        vll v,tree(4*n,0);
        for(ll j=0,temp;j<n;j++)
        {
            scanf("%lld",&temp);
            v.pb(temp);
        }
        build_tree(tree,v,0,n-1,0);
//        for(ll j=0;j<tree.size();j++)printf("")
//            cout<<tree[i]<< " ";
        printf("Case %lld:\n",i);
        while(q--)
        {
            ll l,r;
            scanf("%lld %lld",&l,&r);
            printf("%lld\n",query(tree,l-1,r-1,0,n-1,0));
        }
    }

   // show
    return 0;
}
void build_tree(vll &tree,vll &a,ll l,ll r,ll pos)
{
    if(l>=r)
    {
        tree[pos]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build_tree(tree,a,l,mid,(2*pos)+1);
    build_tree(tree,a,mid+1,r,(2*pos)+2);
    tree[pos]=min(tree[(2*pos)+1],tree[(2*pos)+2]);
}
ll query(vll &tree,ll l,ll r,ll L,ll R,ll pos)
{

    if(r<L || l>R)
        return INT_MAX;
    if(l<=L && r>=R)
        return tree[pos];
    ll mid=(L+R)/2;
    ll x=query(tree,l,r,L,mid,(2*pos)+1);
    ll y=query(tree,l,r,mid+1,R,(2*pos)+2);
    return min(x,y);
}
void FAST_IO()
{
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    //cout.setf(ios::fixed);
//    //cout.precision(20);
//#ifndef _offline
//    //freopen("input.txt", "r", stdin);
//    //freopen("output.txt", "w", stdout);
//#endif
}
