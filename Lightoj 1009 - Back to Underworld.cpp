#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int maximum(vector<int> G[],queue<int> nodes);
bool visited[1000001];
int main()
{
    int t,u,v,i,n;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        vector<int> G[20002];
        queue<int> nodes;
        cin>>n;
        for(int j=0;j<20001;j++)
        {
            visited[j]=false;
        }

        while(n--)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cout<<"Case "<<i<<": "<<maximum(G,nodes)<<endl;
    }
    return 0;
}
int maximum(vector<int> G[],queue<int> nodes)
{
    int vamp=1,lycan=0;
    nodes.push(1);
    visited[1]=true;
    bool race=false;
    while(!nodes.empty())
    {
        int u=nodes.front();
        //cout<<u<<" "<<vamp<<" "<<lycan<<endl;
        nodes.pop();
        for(int i=0;i<G[u].size();i++)
        {
            if(!visited[G[u][i]])
            {
                visited[G[u][i]]=true;
                nodes.push(G[u][i]);
                if(race)
                {
                    vamp++;
                }
                else
                {
                    lycan++;
                }
            }
        }
        if(race)
            race=false;
        else
            race=true;
    }
    //cout<<lycan<<" "<<vamp<<endl;
    if(vamp>lycan)
        return vamp;
    return lycan;

}
