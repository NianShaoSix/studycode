#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

// 图的边结构体
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// 图的顶点结构体
struct Vertex {
    std::vector<Edge> edges;
};

// Dijkstra算法计算单源最短路径
std::vector<int> dijkstra(const std::vector<Vertex>& graph, int start) {
    int n = graph.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (const Edge& edge : graph[u].edges) {
            int v = edge.to;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// 深度优先搜索找到从start到end的路径
bool dfs(const std::vector<Vertex>& graph, int start, int end, std::vector<bool>& visited, std::vector<int>& path) {
    if (start == end) return true;
    visited[start] = true;
    for (const Edge& edge : graph[start].edges) {
        int v = edge.to;
        if (!visited[v]) {
            path.push_back(v);
            if (dfs(graph, v, end, visited, path)) return true;
            path.pop_back();
        }
    }
    return false;
}

std::vector<Vertex> buildGraph() {
    std::vector<Vertex> graph(6);

    // 顶点0的邻居
    graph[0].edges.push_back(Edge(1, 4));
    graph[0].edges.push_back(Edge(2, 2));

    // 顶点1的邻居
    graph[1].edges.push_back(Edge(3, 5));
    graph[1].edges.push_back(Edge(2, 1));

    // 顶点2的邻居
    graph[2].edges.push_back(Edge(3, 8));
    graph[2].edges.push_back(Edge(4, 10));

    // 顶点3的邻居
    graph[3].edges.push_back(Edge(4, 2));
    graph[3].edges.push_back(Edge(5, 6));

    // 顶点4的邻居
    graph[4].edges.push_back(Edge(5, 3));

    return graph;
}

int main() {
    std::vector<Vertex> graph = buildGraph();

    // 1. 计算最短路径
    std::vector<int> shortestPath = dijkstra(graph, 0);
    std::cout << "Shortest paths from vertex 0:" << std::endl;
    for (int i = 0; i < shortestPath.size(); ++i) {
        std::cout << "To vertex " << i << ": " << shortestPath[i] << std::endl;
    }

    // 2. 寻找任意两点间路径（例如从0到5）
    std::vector<bool> visited(graph.size(), false);
    std::vector<int> path;
    path.push_back(0);
    if (dfs(graph, 0, 5, visited, path)) {
        std::cout << "Path from 0 to 5: ";
        for (int v : path) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path from 0 to 5 found." << std::endl;
    }

    return 0;
}