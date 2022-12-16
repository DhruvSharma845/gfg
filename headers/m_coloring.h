#pragma once
#include <vector>
#include <undirected_unweighted_graph.h>

class MColoringGraph {
private:
    bool recursiveColoring(UndirectedUnweightedGraph<int>& graph, int currentVertex, int m, std::vector<int>& colors, std::vector<bool>& visited);
    bool isSafeColor(UndirectedUnweightedGraph<int>& graph, std::vector<int>& colors, int color, int currentVertex);
public:
    bool isMColorable(UndirectedUnweightedGraph<int>& graph, int m);
};

bool MColoringGraph::isMColorable(UndirectedUnweightedGraph<int>& graph, int m) {
    std::vector<bool> visited(graph.getNumOfVertices(), false);
    std::vector<int> colors(graph.getNumOfVertices(), -1);

    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        if(visited[i] == false) {
            if(recursiveColoring(graph, i, m, colors, visited) == false) {
                return false;
            }
        }
    }
    return true;
}

bool MColoringGraph::recursiveColoring(
    UndirectedUnweightedGraph<int>& graph, 
    int currentVertex, 
    int m, 
    std::vector<int>& colors, 
    std::vector<bool>& visited) {
        if(currentVertex == graph.getNumOfVertices()) {
            return true;
        }
        visited[currentVertex] = true;
        for(int i = 0; i < m; ++i) {
            if(isSafeColor(graph, colors, i, currentVertex)) {
                colors[currentVertex] = i;
                if(recursiveColoring(graph, currentVertex + 1, m, colors, visited) == true) {
                    return true;
                }
                colors[currentVertex] = -1;
            }
        }
        return false;
}

bool MColoringGraph::isSafeColor(UndirectedUnweightedGraph<int>& graph, std::vector<int>& colors, int color, int currentVertex) {
    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        if(graph.hasEdge(currentVertex, i) && colors[i] == color) {
            return false;
        }
    }
    return true;
}