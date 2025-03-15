#include "dijkstras.h"

void test_shortest_path() {
    vector<Edge> zero = {Edge(0, 2, 3), Edge(0, 5, 2)};
    vector<Edge> one = {};
    vector<Edge> two = {Edge(2, 4, 1), Edge(2, 5, 2), Edge(2, 3, 4)};
    vector<Edge> three = {Edge(3, 1, 1)};
    vector<Edge> four = {Edge(4, 1, 2)};
    vector<Edge> five = {Edge(5, 2, 2), Edge(5, 4, 3), Edge(5, 1, 6), Edge(5, 6, 5)};
    vector<Edge> six = {Edge(6, 1, 2)};
    
    vector<vector<Edge>> g = {zero, one, two, three, four, five, six};
    Graph G {g, 7};
    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> result = extract_shortest_path(distances, previous, 1);
    print_path(result, 10);
}

void test_small() {
    Graph g;
    file_to_graph("src/small.txt", g);
    for (int i=0; i<g.numVertices; ++i) {
        vector<int> previous (g.numVertices, -1);
        vector<int> distances = dijkstra_shortest_path(g, 0, previous);
        vector<int> result = extract_shortest_path(distances, previous, i);
        print_path(result, 10);
    }
}

int main() {
    // test_shortest_path();
    test_small();
}