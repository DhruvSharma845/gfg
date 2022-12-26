#pragma once

#include <vector>
#include <utility>

class DirectedWeightedGraph {
private:
    using Entry = std::pair<int, int>;
public:
    DirectedWeightedGraph(int vertices): numOfVertices{vertices}, adjList{std::vector<std::vector<Entry>>(vertices, std::vector<Entry>())} {}
    void addEdge(int x, int y, int weight);
    int getNumOfVertices() const { return numOfVertices; }
    std::vector<Entry>& getNeighbors(int x) { return adjList[x]; } 
    Entry getEdge(int x, int y);
private:
    std::vector<std::vector<Entry>> adjList;
    int numOfVertices;
};

void DirectedWeightedGraph::addEdge(int x, int y, int weight) {
    adjList[x].push_back(std::make_pair(y, weight));
}

DirectedWeightedGraph::Entry DirectedWeightedGraph::getEdge(int x, int y) { 
    return *std::find_if(adjList[x].begin(), adjList[x].end(), [=](const Entry& a) { return a.first == y; });
}