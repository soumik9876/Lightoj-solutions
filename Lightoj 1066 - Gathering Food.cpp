
// Problem : 1066 - Gathering Food
// Contest : LightOJ
// URL : http://lightoj.com/volume_showproblem.php?problem=1066
// Memory Limit : 32.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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

char grid[11][11];
int c1,c2,alpha=0,n;
char cur='B';
int bfs(int dis)
{
    int dist[n][n],mx=0;
    bool visited[n][n]={};
    
    queue< pii > q;
    q.push(mp(c1,c2));
    visited[c1][c2]=true;
    dist[c1][c2]=dis;
    while(!q.empty())
    {
        pii node=q.front();
        q.pop();
        
        
        //cout<<node.F<<" "<<node.S<<" "<<dist[node.F][node.S]<<" "<<cur<<" "<<alpha<<endl;
        if(node.F>0)
        {
            if(visited[node.F-1][node.S]==false &&((grid[node.F-1][node.S]<=cur && grid[node.F-1][node.S]>='A') || grid[node.F-1][node.S]=='.'))
            {
                
                q.push(mp(node.F-1,node.S));
                visited[node.F-1][node.S]=true;
                dist[node.F-1][node.S]=dist[node.F][node.S]+1;
                if(grid[node.F-1][node.S]==cur)
                {
                    c1=node.F-1,c2=node.S;
                    return dist[node.F][node.S]+1;  
                }              
            }
        }
        if(node.F<n-1)
        { 
            if(visited[node.F+1][node.S]==false && ((grid[node.F+1][node.S]<=cur && grid[node.F+1][node.S]>='A') || grid[node.F+1][node.S]=='.'))
            {
                
                q.push(mp(node.F+1,node.S));
                visited[node.F+1][node.S]=true;
                dist[node.F+1][node.S]=dist[node.F][node.S]+1;
                if(grid[node.F+1][node.S]==cur)
                {
                    c1=node.F+1,c2=node.S;
                    return dist[node.F][node.S]+1;  
                }   
            }
        }
        if(node.S>0)
        {
            if(visited[node.F][node.S-1]==false &&( (grid[node.F][node.S-1]<=cur && grid[node.F][node.S-1]>='A')  || grid[node.F][node.S-1]=='.'))
            {
                q.push(mp(node.F,node.S-1));
                visited[node.F][node.S-1]=true;
                dist[node.F][node.S-1]=dist[node.F][node.S]+1;
                if(grid[node.F][node.S-1]==cur)
                {
                    c1=node.F,c2=node.S-1;
                    return dist[node.F][node.S]+1;  
                }    
            }
        }
        if(node.S<n-1)
        {
            if(visited[node.F][node.S+1]==false && ((grid[node.F][node.S+1]<=cur && grid[node.F][node.S+1]>='A') || grid[node.F][node.S+1]=='.'))
            {
                
                q.push(mp(node.F,node.S+1));
                visited[node.F][node.S+1]=true;
                dist[node.F][node.S+1]=dist[node.F][node.S]+1;
                if(grid[node.F][node.S+1]==cur)
                {
                    c1=node.F,c2=node.S+1;
                    return dist[node.F][node.S]+1;  
                }  
            }
        }
        
    }
    return -1;
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
        cin>>n;
        alpha=0;
        cur='B';
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]>='A' && grid[i][j]<='Z')
                    alpha++;
                if(grid[i][j]=='A')
                    c1=i,c2=j; 
            }
        }
        int ans=0,b=0;
        while(1)
        {
            if(cur-64==alpha+1)
                break;
            b=bfs(ans);
            if(b==-1)
                break;
            ans=b;
            cur++;
            //cout<<ans<<" "<<cur<<endl;
            
            
        }
        cout<<"Case "<<cn<<": ";
        if(b==-1)
        {
            cout<<"Impossible"<<endl;
        }
        else
            cout<<ans<<endl;
    }
    return 0;
}

