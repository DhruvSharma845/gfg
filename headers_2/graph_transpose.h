#pragma once

#include <directed_unweighted_graph.h>

class DirectedGraphTranspose {
public:
    DirectedUnweightedGraph<int> findTranspose(const DirectedUnweightedGraph<int>& graph);
};

DirectedUnweightedGraph<int> DirectedGraphTranspose::findTranspose(const DirectedUnweightedGraph<int>& graph) {
    DirectedUnweightedGraph<int> g(graph.getNumOfVertices());
    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        auto neighbors = graph.getNeighbors(i);
        for(const auto& neighbor: neighbors) {
            g.addEdge(neighbor, i);
        }
    }
    return g;
}