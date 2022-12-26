#pragma once

#include <vector>
#include <stack>
#include <limits>

#include <directed_weighted_graph.h>

class ShortestPathAcyclicGraph {
private:
    std::vector<int> topologicalOrder(DirectedWeightedGraph& graph);
    void topologicalOrder(DirectedWeightedGraph& graph, int vertex, std::vector<bool>& visited, std::stack<int>& st);
public:
    std::vector<int> getShortestDistances(DirectedWeightedGraph& graph, int source);
};

std::vector<int> ShortestPathAcyclicGraph::getShortestDistances(DirectedWeightedGraph& graph, int source) {
    auto topOrder = topologicalOrder(graph);
    std::vector<int> distances(graph.getNumOfVertices(), std::numeric_limits<int>::max());
    distances[source] = 0;
    for(auto v: topOrder) {
        if(distances[v] != std::numeric_limits<int>::max()) {
            for(auto neighbor: graph.getNeighbors(v)) {
                if(distances[neighbor.first] > distances[v] + graph.getEdge(v, neighbor.first).second) {
                    distances[neighbor.first] = distances[v] + graph.getEdge(v, neighbor.first).second;
                }   
            }
        }
    }
    return distances;
}

std::vector<int> ShortestPathAcyclicGraph::topologicalOrder(DirectedWeightedGraph& graph) {
    std::stack<int> st;
    std::vector<bool> visited(graph.getNumOfVertices(), false);
    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        if(visited[i] == false) {
            topologicalOrder(graph, i, visited, st);
        }
    }

    std::vector<int> res;
    res.reserve(st.size());
    int stSz = st.size();
    while(stSz > 0) {
        res.push_back(st.top());
        st.pop();
        --stSz;
    }
    return res;
}

void ShortestPathAcyclicGraph::topologicalOrder(DirectedWeightedGraph& graph, int vertex, std::vector<bool>& visited, std::stack<int>& st) {
    visited[vertex] = true;
    for(auto neighbor: graph.getNeighbors(vertex)) {
        if(visited[neighbor.first] == false) {
            topologicalOrder(graph, neighbor.first, visited, st);
        }
    }
    st.push(vertex);
}