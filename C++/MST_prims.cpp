#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge 
{
    int dest;
    int weight;
};

void primMST(const vector<vector<Edge>>& graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const Edge& e : graph[u])
        {
            int v = e.dest;
            int weight = e.weight;
            if (!inMST[v] && weight < key[v]) 
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << key[i] << endl;
}

int main() 
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    cout << "Enter the edges and their weights (source destination weight):\n";
    for (int i = 0; i < E; ++i) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    primMST(graph, V);

    return 0;
}
