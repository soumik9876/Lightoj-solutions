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
void update(vector < pll > &tree,ll node,ll a,ll b,ll i,ll j,ll x)
{
    if(a>j || b<i)
        return;
    if(a>=i && b<=j)
    {
        tree[node].S+=x;
        tree[node].F+=(x*(b-a+1));
        return;
    }
    ll left=(node<<1)+1;
    ll right=left+1;
    ll mid=mid(a,b);
    update(tree,left,a,mid,i,j,x);
    update(tree,right,mid+1,b,i,j,x);
    tree[node].F=tree[left].F+tree[right].F+(tree[node].S*(b-a+1));
}
ll query(vector < pll > &tree,ll node,ll a,ll b,ll i,ll j,ll carry)
{
    if(a>j || b<i)
        return 0;
    if(a>=i && b<=j)
        return tree[node].F+(carry*(b-a+1));
    ll left=(node<<1)+1;
    ll right=left+1;
    ll mid=mid(a,b);
    ll val1=query(tree,left,a,mid,i,j,carry+tree[node].S);
    ll val2=query(tree,right,mid+1,b,i,j,carry+tree[node].S);
    return val1+val2;
}
int main()
{
    //KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        vector< pll > tree(4*n+10);
        //cout<<"Case "<<tc<<":"<<endl;
        printf("Case %d:\n",tc);
        while(q--)
        {
            ll x,y,v;
            int check;
            scanf("%d",&check);

            if(!check)
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                update(tree,0,0,n-1,x,y,v);
//                for(auto i:tree)
//                    cout<<i<< " ";
//                cout<<endl;
            }
            else
            {
                scanf("%lld %lld",&x,&y);
                ll ans=query(tree,0,0,n-1,x,y,0);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}


