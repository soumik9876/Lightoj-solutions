#include<bits/stdc++.h>
#define time clock_t tStart = clock();
#define show printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll                    long long int
#define loop(a,b)             for(int i=a;i<=b;++i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
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
#define cerr if(0)cerr
using namespace std;
int query_tree(vi &tree,int l,int r,int st,int sp,int node)
{
    if(l > sp || r < st)
        return 0;
    if(st >= l && sp <= r)
        return tree[node];
    int mid = st+((sp-st)>>1);
    int lft = (node<<1) + 1;
    int rght = lft + 1;
    int sum = query_tree(tree,l,r,st,mid,lft);
    sum += query_tree(tree,l,r,mid + 1, sp , rght);
    return sum;
}
void update_tree(vi &tree,int index,int value,int st,int sp,int node,bool flag)
{
    if(st>index || sp<index)
        return;
    if(st==index && sp==index)
    {
        if(!flag)
            printf("%d\n",tree[node]);
        tree[node]=flag?tree[node]+value:0;
        return ;
    }

    int mid=st+((sp-st)>>1);
    int lft=(node<<1)+1;
    int rght=lft+1;
    update_tree(tree,index,value,st,mid,lft,flag);
    update_tree(tree,index,value,mid+1,sp,rght,flag);
    tree[node]=tree[lft]+tree[rght];
}

void build_segment_tree(vi &tree, vi &v, int st , int sp , int node){
    if(st==sp){
        tree[node] = v[st];
        return ;
    }

    int mid = st + ((sp-st)>>1);
    int lft = (node<<1) + 1;
    int rght = lft + 1;
    build_segment_tree(tree,v,st, mid , lft);
    build_segment_tree(tree,v,mid+1, sp , rght);
    tree[node] = tree[lft] + tree[rght];
}
void ara_print(vi &v)
{
    for(auto i:v)
        cerr<<i<< " ";
    cerr<<endl;
}
void solve(int caseno){
    printf("Case %d:\n",caseno);
    int n, q;
    scanf("%d%d",&n,&q);
    vector <int > v(n);
    for(int &x : v)
        scanf("%d",&x);
    vi tree(4*n);
    build_segment_tree(tree,v,0,n-1,1);

    while(q--){

        int k;
        scanf("%d",&k);
        if(k==1){
            int index ;
            scanf("%d",&index);
            update_tree(tree,index,0,0,n-1,1,false);
        }
        else if(k==2){
            int index, value;
            scanf("%d%d",&index,&value);
            update_tree(tree,index,value,0,n-1,1,true);
        }
        else if(k==3){
            int l , r;
            scanf("%d%d",&l,&r);
            int ans=query_tree(tree,l,r,0,n-1,1);
            printf("%d\n",ans);
        }



    }

}

int main()
{

    #ifdef _soumik
        freopen("input.txt", "r", stdin);
    #endif
    int n,caseno=1;scanf("%d",&n);
    while(n--)
        solve(caseno++);

    return 0;
}


