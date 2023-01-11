#pragma once

#include <vector>
#include <stack>

#include <directed_unweighted_graph.h>

template <typename T>
class TopologicalSort {
public:
    std::vector<T> doSort(const DirectedUnweightedGraph<T>& graph);
private:
    void dfsRecursive(const DirectedUnweightedGraph<T>& graph, int vertex, std::stack<T>& st, std::vector<bool>& visited);
};

template <typename T>
std::vector<T> TopologicalSort<T>::doSort(const DirectedUnweightedGraph<T>& graph) {
    std::stack<T> st;
    std::vector<bool> visited(graph.getNumOfVertices(), false);
    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        if(visited[i] == false) {
            dfsRecursive(graph, i, st, visited);
        }
    }
    std::vector<int> res(st.size());
    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        res[i] = st.top();
        st.pop();
    }
    return res;
}

template <typename T>
void TopologicalSort<T>::dfsRecursive(const DirectedUnweightedGraph<T>& graph, int vertex, std::stack<T>& st, std::vector<bool>& visited) {
    visited[vertex] = true;
    for(const auto& neighbor: graph.getNeighbors(vertex)) {
        if(visited[neighbor] == false) {
            dfsRecursive(graph, neighbor, st, visited);
        }
    }
    st.push(vertex);
}