#include "dijkstras.h"
struct Compare
{
public:
    bool operator()(pair<int, int> const &a, pair<int, int> const &b)
    {
        return a.second > b.second;
    }
};

vector<int> dijkstra_shortest_path(const Graph &G, int source, vector<int> &previous)
{
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    minHeap.push({source, 0});
    distances[source] = 0;
    while (!minHeap.empty())
    {
        int u = minHeap.top().first;
        minHeap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (Edge edge : G[u])
        {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int> &dist, const vector<int> &previous, int destination)
{
    vector<int> copy = dist;
    vector<int> result;
    int next = destination;
    while (next != -1 && dist[next] != 0)
    {
        result.push_back(next);
        next = previous[next];
    }
    reverse(result.begin(), result.end());
    return result;
}

void print_path(const vector<int> &v, int total)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << "Total cost is " << total << endl;
}