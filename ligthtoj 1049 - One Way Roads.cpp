#include<iostream>
using namespace std;
int adj[110][110];
bool visited[110];
int c[110][110];
int t,n,a,b,i;
int lef;
int dfs1(int a);
int dfs2(int a);
int sum=0;
int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        for(int l=0;l<110;l++)
        {
            for(int m=0;m<110;m++)
            {
                adj[l][m]=0;
                c[l][m] = 0;
            }
        }
        int x,y,cost;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>x>>y>>cost;
            adj[x][y]=1;
            c[x][y] = cost;
        }

        for(int l=2;l<=n;l++)
        {
            if(adj[1][l] || adj[l][1])
            {

                lef=l;
                break;
            }
        }
        sum = 0;
        int d1 = dfs1(1);
        sum = 0;
        int d2 = dfs2(1);
        cout << min(d1, d2) << endl;
    }
}
int dfs1(int a)
{

    if(visited[a]) {
        return 0;
    }
    visited[a]=true;

    for(int l=1;l<=n;l++)
    {
        cout<<lef<<"lef\n";
        if(lef == l && a == 1) {
                continue;
        }
        if(!visited[l] && l!=a)
        {
            if(adj[a][l])
               return dfs1(l)+c[l][a];
            else if(adj[l][a]) {

                return dfs1(l) + c[l][a];
            }
        }

    }

}

int dfs2(int a)
{

    if(visited[a]) {
        return 0;
    }
    visited[a]=true;

    for(int l=1;l<=n;l++)
    {

        if(!visited[l] && l!=a)
        {
            if(adj[a][l])
               return dfs2(l)+c[l][a];
            else if(adj[l][a]) {

                return dfs2(l) + c[l][a];
            }
        }

    }

}

