#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

const int INF = 1e9;

int main()
{
    int v, e;
    cout << "n(vertices): ";
    cin >> v;
    cout << "n(edges): ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(v);
    vector<int> dist(v, INF);
    vector<bool> visited(v, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cout << "Start node values from 0" << endl;
    for(int i = 0; i < e; i++)
    {
        int x, y, w;
        cout << "Enter x, y edge with weight w\nx: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        cout << "w: ";
        cin >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    cout << endl << "Edges:" << endl;
    for(int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for(auto edge : graph[i])
        {
            cout << "(" << i << "," << edge.first << " weight:" << edge.second << ") ";
        }
        cout << endl;
    }

    int start = 0;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        if(visited[u]) continue;
        visited[u] = true;

        for(auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for(int i = 0; i < v; i++)
    {
        if(dist[i] == INF)
            cout << "Node " << i << " is unreachable" << endl;
        else
            cout << "Distance to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}
