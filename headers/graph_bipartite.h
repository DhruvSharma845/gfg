#pragma once

#include <unordered_map>
#include <queue>
#include <undirected_unweighted_graph.h>

class IsGraphBipartite {
public:
    enum class Color {RED, GREEN};
    bool isBipartite(UndirectedUnweightedGraph<int>& graph);
};

bool IsGraphBipartite::isBipartite(UndirectedUnweightedGraph<int>& graph) {
    auto src = int{0};
    std::vector<bool> visited(graph.getNumOfVertices(), false);
    std::unordered_map<int, Color> colorMap;

    std::queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        int qSize = q.size();
        while(qSize > 0) {
            int v = q.front();
            q.pop();
            Color vColor = colorMap[v];

            for(const auto& neighbor: graph.getNeighbors(v)) {
                if(colorMap.find(neighbor) != colorMap.end() && colorMap[neighbor] == vColor) {
                    return false;
                }
                if(visited[neighbor] == false) {
                    q.push(neighbor);
                    Color newColor = vColor == Color::RED ? Color::GREEN : Color::RED;
                    colorMap[neighbor] = newColor;
                    visited[neighbor] = true;
                }
            }
            --qSize;
        }
    }
    return true;
}