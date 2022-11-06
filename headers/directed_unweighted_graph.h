#pragma once

#include <vector>

template <typename T>
class DirectedUnweightedGraph {
public:
    DirectedUnweightedGraph(int vertices): numOfVertices{vertices}, adjList{std::vector<std::vector<T>>(vertices, std::vector<T>())} {}
    void addEdge(int x, int y);
    int getNumOfVertices() const { return numOfVertices; }
    std::vector<T>& getNeighbors(int x) { return adjList[x]; } 
private:
    std::vector<std::vector<T>> adjList;
    int numOfVertices;
};

template <typename T>
void DirectedUnweightedGraph<T>::addEdge(int x, int y) {
    adjList[x].push_back(y);
}