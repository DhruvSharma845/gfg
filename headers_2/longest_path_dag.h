#pragma once

#include <vector>
#include <stack>

#include <directed_weighted_graph.h>

class LongestPathInDAG {
private:
    void topologicalSort(DirectedWeightedGraph& dag, std::vector<bool>& visited, int vertex, std::stack<int>& st);
public:
    std::vector<int> getDistancesFromSource(const DirectedWeightedGraph& dag, int source);
};

void LongestPathInDAG::topologicalSort(DirectedWeightedGraph& dag, std::vector<bool>& visited, int vertex, std::stack<int>& st) {
    visited[vertex] = true;
    for(const auto& neighbor: dag.getNeighbors(vertex)) {
        if(visited[neighbor.first] == false) {
            topologicalSort(dag, visited, neighbor.first, st);
        }
    }
    st.push(vertex);
}

std::vector<int> LongestPathInDAG::getDistancesFromSource(const DirectedWeightedGraph& dag, int source) {
    std::stack<int> st;
    std::vector<bool> visited(dag.getNumOfVertices(), false);
    for(int i = 0; i < dag.getNumOfVertices(); ++i) {
        if(visited[i] == false) {
            topologicalSort(const_cast<DirectedWeightedGraph&>(dag), visited, 0, st);
        }
    }
    std::vector<int> distances(dag.getNumOfVertices(), std::numeric_limits<int>::max());
    distances[source] = 0;

    while(!st.empty()) {
        int v = st.top();
        st.pop();

        if(distances[v] == std::numeric_limits<int>::max()) {
            continue;
        }

        for(const auto& neighbor: const_cast<DirectedWeightedGraph&>(dag).getNeighbors(v)) {
            
            if(distances[neighbor.first] == std::numeric_limits<int>::max() || distances[neighbor.first] < neighbor.second + distances[v]) {
                distances[neighbor.first] = neighbor.second + distances[v];
            }
        }
    }
    
    return distances;
}