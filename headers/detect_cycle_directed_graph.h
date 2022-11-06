#pragma once

#include <directed_unweighted_graph.h>

template <typename T>
class CycleDetectorGraph {
public:
    bool hasCycle(DirectedUnweightedGraph<T>& graph);
private:
    bool hasCycleUtil(DirectedUnweightedGraph<T>& graph, int src, std::vector<bool>& visited, std::vector<bool>& isRecursionStack);
};

template <typename T>
bool CycleDetectorGraph<T>::hasCycle(DirectedUnweightedGraph<T>& graph) {
    std::vector<bool> visited(graph.getNumOfVertices(), false);
    std::vector<bool> isRecursionStack(graph.getNumOfVertices(), false);

    for(int i = 0; i < graph.getNumOfVertices(); ++i) {
        if(visited[i] == false) {
            if(hasCycleUtil(graph, i, visited, isRecursionStack) == true) {
                return true;
            } 
        }
    }
    return false;
}

template <typename T>
bool CycleDetectorGraph<T>::hasCycleUtil(
    DirectedUnweightedGraph<T>& graph, 
    int src, 
    std::vector<bool>& visited, 
    std::vector<bool>& isRecursionStack
) {
    visited[src] = true;
    isRecursionStack[src] = true;
    for(auto neighbor: graph.getNeighbors(src)) {
        if(visited[neighbor] == true && isRecursionStack[neighbor] == true) {
            return true;
        }
        if(visited[neighbor] == false) { 
            if(hasCycleUtil(graph, neighbor, visited, isRecursionStack) == true) {
                return true;
            }
        }
    }
    isRecursionStack[src] = false;
    return false;
}