#pragma once

#include <undirected_unweighted_graph.h>

template <typename T>
class DepthFirstSearch {
private:
    void doDFSUtil(UndirectedUnweightedGraph<T> graph, int ver, std::vector<bool>& visited, std::vector<int>& result);
public:
    std::vector<int> doDFS(UndirectedUnweightedGraph<T> graph, int src);
};

template <typename T>
void DepthFirstSearch<T>::doDFSUtil(UndirectedUnweightedGraph<T> graph, int ver, std::vector<bool>& visited, std::vector<int>& result) {
    visited[ver] = true;
    result.push_back(ver);
    for(const auto& neighbour: graph.getNeighbors(ver)) {
        if(visited[neighbour] == false) {
            doDFSUtil(graph, neighbour, visited, result);
        }
    }
}

template <typename T>
std::vector<int> DepthFirstSearch<T>::doDFS(UndirectedUnweightedGraph<T> graph, int src) {
    std::vector<bool> visited(graph.getNumOfVertices(), false);
    std::vector<int> result;
    doDFSUtil(graph, src, visited, result);
    return result;
}