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
#define vp                    vector< pair<char,int> >
using namespace std;

void lazy_update(vp &tree,int node,int a,int b,int l,int r)
{
    if(a>r || b<l)
    {
        return;
    }
    if(a>=l && b<=r)
    {

        tree[node].S^=1;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=a+((b-a)>>1);
    lazy_update(tree,left,a,mid,l,r);
    lazy_update(tree,right,mid+1,b,l,r);
}
void buildtree(vp &tree,char *s,int node,int a,int b)
{
    if(a==b)
    {
        tree[node].first=s[a];
        return;
    }
    int left=(node<<1);
    int right=left+1;
    int mid=a+((b-a)>>1);
    buildtree(tree,s,left,a,mid);
    buildtree(tree,s,right,mid+1,b);
}
int query(vp &tree,int ind,int node,int a,int b,bool carry)
{
    if(a>ind || b<ind)
        return -1;
    if(a==ind && b==ind)
    {
        //cout<<tree[node].F<<" "<<node<<" "<<ind<<" "<<a<<" "<<b<<endl;
        int ans=tree[node].F-'0';
        ans^=tree[node].S;
        return ans^carry;
    }
    int left=node<<1;
    int right=left+1;
    int mid=a+((b-a)>>1);
    int x=query(tree,ind,left,a,mid,carry^tree[node].S);
    int y=query(tree,ind,right,mid+1,b,carry^tree[node].S);
    return max(x,y);
}
int main()
{
    //KAMEHAMEHA
    #ifdef _soumik
        freopen("input.txt", "r", stdin);
    #endif
    int t,cn=1;
    scanf("%d",&t);
    while(t--)
    {

        char s[100000+50];
        printf("Case %d:\n",cn++);
        scanf("%s",s);
        int q,n=strlen(s);
        scanf("%d ",&q);
        vp tree(4*n+10);
        buildtree(tree,s,1,0,n-1);
        while(q--)
        {
            int l,r,ind;
            char c;
            scanf("%c",&c);
            if(c=='I')
            {
                scanf("%d%d ",&l,&r);
                lazy_update(tree,1,0,n-1,l-1,r-1);
            }
            else if(c=='Q')
            {
                scanf("%d ",&ind);
                int ans = query(tree,ind-1,1,0,n-1,0);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
