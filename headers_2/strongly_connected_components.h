#pragma once

#include <vector>
#include <stack>

#include <directed_unweighted_graph.h>
#include <graph_transpose.h>
#include <topological_sorting.h>

class StronglyConnectedComponents {
public:
    using SCCType = std::vector<std::vector<int>>;
private:
    void dfsRecursively(int vertex, const DirectedUnweightedGraph<int>& transposedGraph, std::vector<bool>& visited, std::vector<int>& cc);
    void tsRecursive(const DirectedUnweightedGraph<int>& graph, int vertex, std::stack<int>& st, std::vector<bool>& visited);
public:
    SCCType findSCC(const DirectedUnweightedGraph<int>& graph);
};

void StronglyConnectedComponents::dfsRecursively(int vertex, const DirectedUnweightedGraph<int>& transposedGraph, std::vector<bool>& visited, std::vector<int>& cc) {
    visited[vertex] = true;
    cc.push_back(vertex);
    for(const auto& neighbor: transposedGraph.getNeighbors(vertex)) {
        if(visited[neighbor] == false) {
            dfsRecursively(neighbor, transposedGraph, visited, cc);
        }
    }
}

void StronglyConnectedComponents::tsRecursive(const DirectedUnweightedGraph<int>& graph, int vertex, std::stack<int>& st, std::vector<bool>& visited) {
    visited[vertex] = true;
    for(const auto& neighbor: graph.getNeighbors(vertex)) {
        if(visited[neighbor] == false) {
            tsRecursive(graph, neighbor, st, visited);
        }
    }
    st.push(vertex);
}

StronglyConnectedComponents::SCCType StronglyConnectedComponents::findSCC(const DirectedUnweightedGraph<int>& graph) {
    std::stack<int> st;
    std::vector<bool> visitedF(graph.getNumOfVertices(), false);
    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        if(visitedF[i] == false) {
            tsRecursive(graph, i, st, visitedF);
        }
    }
    DirectedGraphTranspose dgt;
    DirectedUnweightedGraph<int> transposedGraph = dgt.findTranspose(graph);

    StronglyConnectedComponents::SCCType res;

    std::vector<bool> visited(graph.getNumOfVertices(), false);
    while(!st.empty()) {
        int i = st.top();
        st.pop();
        if(visited[i] == false) {
            std::vector<int> cc;
            dfsRecursively(i, transposedGraph, visited, cc);
            res.push_back(cc);
        }
    }

    return res;
}