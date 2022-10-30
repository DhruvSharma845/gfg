#pragma once 

#include <queue>

#include <undirected_unweighted_graph.h>

template <typename T>
class BreadthFirstSearch {
public:
    std::vector<int> doBFS(UndirectedUnweightedGraph<T> graph, int src);
};

template <typename T>
std::vector<int> BreadthFirstSearch<T>::doBFS(UndirectedUnweightedGraph<T> graph, int src) {
    std::queue<int> q;
    std::vector<bool> visited(graph.getNumOfVertices(), false);

    std::vector<int> res;
    res.reserve(graph.getNumOfVertices());

    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(const auto& neighbor: graph.getNeighbors(node)) {
            if(visited[neighbor] == false) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return res;
}