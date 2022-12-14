#pragma once

#include <vector>
#include <algorithm>

template <typename T>
class UndirectedUnweightedGraph {
public:
    UndirectedUnweightedGraph(int vertices): numOfVertices{vertices}, adjList{std::vector<std::vector<T>>(vertices, std::vector<T>())} {}
    void addEdge(int x, int y);
    int getNumOfVertices() const { return numOfVertices; }
    std::vector<T>& getNeighbors(int x) { return adjList[x]; }
    bool hasEdge(int x, int y); 
private:
    std::vector<std::vector<T>> adjList;
    int numOfVertices;
};

template <typename T>
void UndirectedUnweightedGraph<T>::addEdge(int x, int y) {
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

template <typename T>
bool UndirectedUnweightedGraph<T>::hasEdge(int x, int y) {
    auto it = std::find(adjList[x].begin(), adjList[x].end(), y);
    return (it != adjList[x].end());
}