#pragma once

#include <vector>
#include <algorithm>

#include <undirected_unweighted_graph.h>

class EulerianPathAndCycleInUndirectedGraph {
public:
    enum class EulerType { EulerianPath, EulerianCycle, NotEulerian };
private:
    EulerType findEulerianType(UndirectedUnweightedGraph<int>& graph);
    void dfsRecursive(UndirectedUnweightedGraph<int>& graph, int vertex, std::vector<bool>& visited);
public:
    bool hasEulerianPath(UndirectedUnweightedGraph<int>& graph);
    bool hasEulerianCycle(UndirectedUnweightedGraph<int>& graph);
};

void EulerianPathAndCycleInUndirectedGraph::dfsRecursive(UndirectedUnweightedGraph<int>& graph, int vertex, std::vector<bool>& visited) {
    visited[vertex] = true;
    for(const auto& neighbor: graph.getNeighbors(vertex)) {
        if(visited[neighbor] == false) {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

EulerianPathAndCycleInUndirectedGraph::EulerType EulerianPathAndCycleInUndirectedGraph::findEulerianType(UndirectedUnweightedGraph<int>& graph) {
    std::vector<bool> visited(graph.getNumOfVertices(), false);
    dfsRecursive(graph, 0, visited);
    auto it = std::find(visited.begin(), visited.end(), false);
    if(it != visited.end()) {
        return EulerType::NotEulerian;
    }

    int oddDegreeCount = 0;
    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        if(graph.getNeighbors(i).size() % 2 != 0) {
            ++oddDegreeCount;
        }
    }

    if(oddDegreeCount == 2) {
        return EulerType::EulerianPath;
    } else if(oddDegreeCount == 0) {
        return EulerType::EulerianCycle;
    }
    return EulerType::NotEulerian;
}

bool EulerianPathAndCycleInUndirectedGraph::hasEulerianPath(UndirectedUnweightedGraph<int>& graph) {
    return (findEulerianType(graph) == EulerType::EulerianPath);
}

bool EulerianPathAndCycleInUndirectedGraph::hasEulerianCycle(UndirectedUnweightedGraph<int>& graph) {
    return (findEulerianType(graph) == EulerType::EulerianCycle);
}