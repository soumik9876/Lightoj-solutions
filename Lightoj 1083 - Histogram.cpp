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
int mx=0;
void buildtree(vi &ara,vector < pii > &tree,int a,int b,int node)
{
    if(a==b)
    {
        tree[node].F=ara[a];
        tree[node].S=a;
        return;
    }
    int left=(node<<1);
    int right=left+1;
    int mid=mid(a,b);
    buildtree(ara,tree,a,mid,left);
    buildtree(ara,tree,mid+1,b,right);
    tree[node]=min(tree[left],tree[right]);
}
pii query(vector< pii > &tree,int a,int b,int x,int y,int node)
{
    if(a>y || b<x)
    {
        return mp(100000000,-1);
    }
    if(a>=x && b<=y)
        return tree[node];
    int left=(node<<1);
    int right=left+1;
    int mid=mid(a,b);
    pii l=query(tree,a,mid,x,y,left);
    pii r=query(tree,mid+1,b,x,y,right);
    return min(l,r);
}
void mins(int a,int b,vector< pii > &tree,int n)
{
    if(b<a)
        return;
    pii ans=query(tree,0,n-1,a,b,1);
    int total=(ans.F*(b-a+1));
    mx=max(mx,total);
    mins(a,ans.S-1,tree,n);
    mins(ans.S+1,b,tree,n);
}
int main()
{
    KAMEHAMEHA
//    #ifdef _soumik
//        freopen("input.txt", "r", stdin);
//    #endif
    int t;
    cin>>t;
    for(int cn=1;cn<=t;cn++)
    {
        int n;
        cin>>n;
        vi a;
        vector < pii > tree(4*n);
        for(int i=0,temp;i<n;i++)
        {
            cin>>temp;
            a.eb(temp);
        }
        mx=0;
        buildtree(a,tree,0,n-1,1);
        mins(0,n-1,tree,n);
        cout<<"Case "<<cn<<": "<<mx<<endl;
    }
    return 0;
}


