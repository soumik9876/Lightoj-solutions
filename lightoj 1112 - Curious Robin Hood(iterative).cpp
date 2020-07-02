
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
int query_tree(vi &tree,int l,int r)
{
    int sum = 0;
    while(l < r)
    {
        if(l&1)
        {
            sum += tree[l];
            l += 1;
        }
        if(r & 1)
        {
            r -= 1;
            sum += tree[r];

        }
        l >>=1,r>>=1;

    }
    return sum ;
}

void update_tree(vi &tree,int index,int n, int value,bool flag)
{
    if(flag==false)
        printf("%d\n",tree[index]);
    tree[index] = flag?tree[index] += value : 0;
    while(index > 1){
        tree[index >> 1] = tree[index] + tree[index ^ 1];
        index >>=1;
    }

}

void build_segment_tree(vi &tree,int n)
{
    for(int i = n - 1; i > 0 ; i--)
        tree[i] = tree[i<<1] + tree[(i<<1)+1];
    //for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}
void ara_print(vi &v)
{
    for(auto i:v)
        cerr<<i<< " ";
    cerr<<endl;
}
void solve(int caseno)
{
    printf("Case %d:\n",caseno);
    int n, q;
    scanf("%d%d",&n,&q);
    vi tree(2*n);

    for(int i = 0 ; i < n; i++)
        scanf("%d",&tree[n+i]);

    ara_print(tree);
    build_segment_tree(tree,n);
    while(q--)
    {
        int k;
        scanf("%d",&k);
        if(k==1)
        {
            int index ;
            scanf("%d",&index);
            update_tree(tree,index+n,n,0,false);
        }
        else if(k==2)
        {
            int index, value;
            scanf("%d%d",&index,&value);
            update_tree(tree,index+n,n, value, true);
        }
        else if(k==3)
        {
            int l, r;
            scanf("%d%d",&l,&r);

            int ans=query_tree(tree,l+n,r+n+1);
            printf("%d\n",ans);
        }
    }
}

int main()
{

#ifdef _soumik
    freopen("input.txt", "r", stdin);
#endif
    int n,caseno=1;
    scanf("%d",&n);
    while(n--)
        solve(caseno++);

    return 0;
}


