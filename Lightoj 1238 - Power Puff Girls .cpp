#include<bits/stdc++.h>
using namespace std;
char grid[21][21];
int t,m,n,i,j,k;
bool visited[21][21];
int dist[21][21];
pair<int,int> a,b,c,h;
queue< pair<int,int> > line;

int bfs(pair<int,int> p);
int main()
{

    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>m>>n;
        for(j=0;j<21;j++)
        {
            for(k=0;k<21;k++)
            {
                grid[j][k]='#';
            }
        }

        for(j=0;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                cin>>grid[j][k];
                if(grid[j][k]=='a')
                    a=make_pair(j,k);
                else if(grid[j][k]=='b')
                    b=make_pair(j,k);
                    else if(grid[j][k]=='h')
                    h=make_pair(j,k);
                    else if(grid[j][k]=='c')
                    c=make_pair(j,k);
            }

        }

        int ans=max(bfs(a),max(bfs(b),bfs(c)));
       // cout<<bfs(distancea,a,h)<<" "<<bfs(distanceb,b,h)<<" "<<bfs(distancec,c,h)<<endl;
//       for(j=0;j<m;j++)
//       {
//           for(k=0;k<n;k++)
//            cout<<distancea[j][k]<<" ";
//           cout<<endl;
//       }
        cout<<"Case "<<i<<": "<< ans<<endl;
    }
}
int bfs(pair<int,int> p)
{
    for(j=0;j<21;j++)
        {
            for(k=0;k<21;k++)
            {
                dist[j][k]=0;
            }
        }
        for(j=0;j<21;j++)
        {
            for(k=0;k<21;k++)
            {
               visited[j][k]=false;
            }
        }
    line.push(p);
    pair<int,int> at;

    visited[at.first][at.second]=true;
    while(!line.empty())
    {
        at=line.front();
        line.pop();

        if(!visited[at.first+1][at.second] && grid[at.first+1][at.second]!='m'&& grid[at.first+1][at.second]!='#')
        {

            visited[at.first+1][at.second] = true;
            dist[at.first+1][at.second] = dist[at.first][at.second]+1;
            line.push(make_pair(at.first+1, at.second));
        }

//        if(visited[at.first+1][at.second] && grid[at.first+1][at.second]!='m'&& grid[at.first+1][at.second]!='#')
//        {
//            dist[at.first+1][at.second] = min(dist[at.first][at.second]+1,dist[at.first+1][at.second]);
//            //line.push(make_pair(at.first+1, at.second));
//        }

        if(!visited[at.first-1][at.second] && grid[at.first-1][at.second]!='m'&& grid[at.first-1][at.second]!='#')
        {
            visited[at.first-1][at.second] = true;
            dist[at.first-1][at.second] = dist[at.first][at.second]+1;
            line.push(make_pair(at.first-1, at.second));
        }
//        if(visited[at.first-1][at.second] && grid[at.first-1][at.second]!='m'&& grid[at.first-1][at.second]!='#')
//        {
//            dist[at.first-1][at.second] = min(dist[at.first][at.second]+1,dist[at.first-1][at.second]);
//            //line.push(make_pair(at.first-1, at.second));
//        }
        if(!visited[at.first][at.second+1] && grid[at.first][at.second+1]!='m'&& grid[at.first][at.second+1]!='#')
        {
            visited[at.first][at.second+1] = true;
            dist[at.first][at.second+1] = dist[at.first][at.second]+1;
            line.push(make_pair(at.first, at.second+1));
        }
//        if(visited[at.first][at.second+1] && grid[at.first][at.second+1]!='m'&& grid[at.first][at.second+1]!='#')
//        {
//            dist[at.first][at.second+1] = min(dist[at.first][at.second]+1,dist[at.first][at.second+1]);
//            //line.push(make_pair(at.first, at.second+1));
//        }
        if(!visited[at.first][at.second-1] && grid[at.first][at.second-1]!='m'&& grid[at.first][at.second-1]!='#')
        {
            visited[at.first][at.second-1] = true;
            dist[at.first][at.second-1] = dist[at.first][at.second]+1;
            line.push(make_pair(at.first, at.second-1));
        }
//        if(visited[at.first][at.second-1] && grid[at.first][at.second-1]!='m'&& grid[at.first][at.second-1]!='#')
//        {
//            dist[at.first][at.second-1] = min(dist[at.first][at.second]+1,dist[at.first][at.second-1]);
//            //line.push(make_pair(at.first, at.second-1));
//        }



    }
    return dist[h.first][h.second];
}
