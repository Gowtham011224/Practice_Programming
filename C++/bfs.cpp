#include<iostream>
using namespace std;
#include<queue>
#include<vector>

int main()
{
    int v,e;
    cout<<"n(vertices):";
    cin>>v;
    cout<<"n(edges):";
    cin>>e;
    vector<vector<int>> graph(v,{0,0});//adjacency matrix
    vector<bool> visit(v,false);
    queue<int> q;
    cout<<"Start node values from 0"<<endl;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cout<<"Enter x,y edge\nx:";
        cin>>x;
        cout<<"y:";
        cin>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }

    cout<<endl<<"Edges:"<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(graph[i][j]==1)
            cout<<"("<<i<<","<<j<<")";
        }
        cout<<endl;
    }

    int s=0;
    q.push(s);
    visit[s]=true;
    cout<<"BFS:\n";
    while(!q.empty())
    {
        for(int j=0;j<v;j++)
        {
            if(graph[s][j]==1 && visit[j]==false)
            {
                q.push(j);
                visit[j]=true;
            }
        }
        int a=q.front();
        q.pop();
        cout<<a<<" ";
        s=q.front();
    }
    return 0;
}