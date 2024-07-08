#include<iostream>
using namespace std;
#include<stack>
#include<vector>

int main()
{
    int v,e;
    cout<<"n(vertices):";
    cin>>v;
    cout<<"n(edges):";
    cin>>e;
    vector<vector<int>> graph(v,{0,0});//upper adjacency matrix
    vector<bool> visit(v,false);
    stack<int> st;
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
    st.push(s);
    visit[s]=true;
    cout<<"DFS:\n";
    cout<<s<<" ";
    int j,f;
    while(!st.empty())
    {
        f=0;
        for(j=0;j<v;j++)
        {
            
            if(graph[s][j]==1 && visit[j]==false)
            {
                st.push(j);
                visit[j]=true;
                f=1;
                s=j;
                break;
            }
        }
        if(f==0)
        {
            st.pop();
            if(!st.empty())
            s=st.top();
        }
        else{
        int a=st.top();
        cout<<a<<" ";
        }
    }
    return 0;
}