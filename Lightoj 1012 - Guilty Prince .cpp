#include<bits/stdc++.h>
using  namespace std;
queue< pair <int,int> > q;
bool visited[21][21];
int t,w,h,i;
char grid[21][21];
int bfs(int x,int y);
int main()
{

    cin>>t;
    for(i=1;i<=t;i++)
    {

        for(int i = 0; i < 21; i++) {
            for(int j = 0; j < 21; j++) {

                grid[i][j] = '#';
            }
        }
        int x,y;
        cin>>w>>h;
        for(int j=0;j<h;j++)
        {
            for(int k=0;k<w;k++)

        {
            cin>>grid[j][k];
            if(grid[j][k]=='@')
            {
                x=j;
                y=k;
            }
        }

        }
        cout <<"Case "<<i<<": "<<bfs(x,y)<<endl;


    }
    return 0;
}
int bfs(int x,int y)
{
    int cnt=1;
    memset(visited, false, sizeof(visited));
    pair<int,int> path;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    while(!q.empty())
    {
        path=q.front();
        q.pop();

//      if(path.first-1<0 || path.first+1 >= h || path.second-1 < 0 || path.second+1 >= w) {
//        continue;
//       }
        {


            if(visited[path.first][path.second+1]==false && grid[path.first][path.second+1]=='.')
            {

                q.push(make_pair(path.first,path.second+1));
                visited[path.first][path.second+1]=true;
                cnt++;
            }
             if(visited[path.first][path.second-1]==false && grid[path.first][path.second-1]=='.')
            {

                q.push(make_pair(path.first,path.second-1));
                visited[path.first][path.second-1]=true;
                cnt++;
            }
             if(visited[path.first-1][path.second]==false && grid[path.first-1][path.second]=='.')
            {

                q.push(make_pair(path.first-1,path.second));
                visited[path.first-1][path.second]=true;
                cnt++;
            }
             if(visited[path.first+1][path.second]==false && grid[path.first+1][path.second]=='.')
            {

                q.push(make_pair(path.first+1,path.second));
                visited[path.first+1][path.second]=true;
                cnt++;
            }

      //  }
//        if(cnt>w*h)
//            break;

}
}
return cnt;
}
