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
void buildtree(vector< pii > &tree,vi &ara,int a,int b,int node)
{
    if(a==b)
    {
        tree[node].F=ara[a];
        tree[node].S=ara[a];
        return;
    }
    int left=(node<<1)+1;
    int right=left+1;
    int mid=b+((a-b)>>1);
    buildtree(tree,ara,a,mid,left);
    buildtree(tree,ara,mid+1,b,right);
    tree[node].F=max(tree[left].F,tree[right].F);
    tree[node].S=min(tree[left].S,tree[right].S);
}
pii query(vector< pii > &tree,int a,int b,int x,int y,int node)
{

    if(a>y || b<x)
        return mp(0,INT_MAX);
    if(a>=x && b<=y)
    {
        //cout<<tree[node].F<< " "<<tree[node].S<<" "<<a<< " "<<b<<endl;
        return mp(tree[node].F,tree[node].S);
    }
    int left=(node<<1)+1;
    int right=left+1;
    int mid=b+((a-b)>>1);
    pii val1=query(tree,a,mid,x,y,left);
    pii val2=query(tree,mid+1,b,x,y,right);
    pii ans=mp(max(val1.F,val2.F),min(val1.S,val2.S));
    //cout<<ans.F<< " "<<ans.S<<endl;
    return ans;
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
        int n,d;
        cin>>n>>d;
        vi ara;
        vector< pii > tree(4*n);
        for(int i=0,temp;i<n;i++)
        {
            cin>>temp;
            ara.eb(temp);
        }
        buildtree(tree,ara,0,n-1,0);
        int diff=0;
//        for(auto i: tree)
//            cout<<i.F<< " "<<i.S<<endl;
        for(int i=0;i<=n-d;i++)
        {
            pii p=query(tree,0,n-1,i,i+d-1,0);
            diff=max(diff,p.F-p.S);
           // cout<<i<< " "<<diff<<endl;
        }
        cout<<"Case "<<tc<<": "<<diff<<endl;
    }
    return 0;
}


