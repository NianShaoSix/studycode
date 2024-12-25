#include <iostream>  
#include <vector>  
#include <limits>  
#include <unordered_map>  
#include <set>  
#include <string>  
#include <algorithm>  

using namespace std;  

struct Edge {  
    int destination;  
    double weight;  
};  

struct Landmark {  
    string name;  
    string description;  
};  

class Graph {  
public:  
    unordered_map<int, Landmark> landmarks; // 存储景点信息  
    unordered_map<int, vector<Edge>> adjList;  

    void addLandmark(int id, const string& name, const string& description) {  
        landmarks[id] = {name, description};  
    }  

    void addEdge(int from, int to, double weight) {  
        adjList[from].push_back({to, weight});  
        adjList[to].push_back({from, weight}); // 无向图  
    }  

    void printAllLandmarks() {  
        cout << "\n公园内所有景点的信息：" << endl;  
        for (const auto& landmark : landmarks) {  
            cout << "景点 ID: " << landmark.first   
                 << ", 名称: " << landmark.second.name   
                 << ", 简介: " << landmark.second.description << endl;  
        }  
    }  

    vector<int> dijkstra(int start, int end) {  
        // 确认起点和终点有效  
        if (landmarks.find(start) == landmarks.end() || landmarks.find(end) == landmarks.end()) {  
            cout << "起点或终点无效，查找失败！" << endl;  
            return {};  
        }  

        unordered_map<int, double> distances;  
        unordered_map<int, int> previous;  
        set<pair<double, int>> nodes;  

        for (const auto& pair : adjList) {  
            distances[pair.first] = numeric_limits<double>::infinity();  
        }  
        distances[start] = 0;  
        nodes.insert({0, start});  

        while (!nodes.empty()) {  
            int current = nodes.begin()->second;  
            nodes.erase(nodes.begin());  

            if (current == end) break;  

            for (const auto& edge : adjList.at(current)) {  
                double newDist = distances[current] + edge.weight;  
                if (newDist < distances[edge.destination]) {  
                    nodes.erase({distances[edge.destination], edge.destination});  
                    distances[edge.destination] = newDist;  
                    previous[edge.destination] = current;  
                    nodes.insert({newDist, edge.destination});  
                }  
            }  
        }  

        // 反向构建路径  
        vector<int> path;  
        for (int at = end; at != 0; at = previous.at(at)) {  
            path.push_back(at);  
        }  
        if (path.empty() || path.back() != start) { // 确保路径有效  
            path.clear();  
        }  
        path.push_back(start);  
        reverse(path.begin(), path.end());  
        return path;  
    }  

    void dfs(int vertex, set<int>& visited, vector<int>& path) {  
        visited.insert(vertex);  
        path.push_back(vertex);  

        // 如果路径长度已达到景点数，记下路径  
        if (path.size() == landmarks.size()) {  
            cout << "游览路径: ";  
            for (int id : path) {  
                cout << landmarks[id].name << " ";  
            }  
            cout << endl;  
        }  

        for (const auto& edge : adjList.at(vertex)) {  
            if (visited.find(edge.destination) == visited.end()) {  
                dfs(edge.destination, visited, path);  
            }  
        }  

        // 回溯  
        visited.erase(vertex);  
        path.pop_back();  
    }  

    void findHamiltonianPath() {  
        set<int> visited;  
        vector<int> path;  
        // 从每个节点出发进行DFS  
        for (const auto& landmark : landmarks) {  
            dfs(landmark.first, visited, path);  
        }  
    }  
};  

void createParkMap(Graph& graph) {  
    // 添加五个固定的公园景点  
    graph.addLandmark(1, "喷泉", "公园的中心，装饰着漂亮的喷泉。");  
    graph.addLandmark(2, "秋千区", "适合儿童的秋千区，欢乐的游乐场。");  
    graph.addLandmark(3, "小树林", "一个安静的小树林，适合散步和放松。");  
    graph.addLandmark(4, "花坛", "五彩斑斓的花坛，吸引了许多游客。");  
    graph.addLandmark(5, "观景台", "提供俯瞰公园的最佳视角。");  

    // 添加道路和距离（用户可自定义）  
    graph.addEdge(1, 2, 10);  
    graph.addEdge(1, 3, 15);  
    graph.addEdge(2, 4, 5);  
    graph.addEdge(3, 5, 20);  
    graph.addEdge(4, 5, 10);  
}  

int main() {  
    Graph graph;  

    // 创建公园地图  
    createParkMap(graph);  
    
    int choice;  
    do {  
        cout << "\n===== 功能菜单 =====\n";  
        cout << "1. 打印所有景点信息\n";  
        cout << "2. 查询最短路径\n";  
        cout << "3. 查询最佳游览路径\n";  
        cout << "4. 退出查询系统\n";  
        cout << "请选择要执行的操作 (1-4): ";  
        cin >> choice;  

        switch (choice) {  
            case 1:  
                graph.printAllLandmarks(); // 打印所有景点信息  
                break;  
            case 2: {  
                int start, end;  
                cout << "请输入起点景点ID和终点景点ID (空格分隔): ";  
                cin >> start >> end;  
                vector<int> shortestPath = graph.dijkstra(start, end);  
                if (!shortestPath.empty()) {  
                    cout << "从景点 " << graph.landmarks[start].name << " 到 "   
                         << graph.landmarks[end].name << " 的最短路径为: ";  
                    for (int id : shortestPath) {  
                        cout << graph.landmarks[id].name << " ";  
                    }  
                    cout << endl;  
                }  
                break;  
            }  
            case 3:  
                cout << "查找最佳游览路径（哈密顿路径）:" << endl;  
                graph.findHamiltonianPath();  
                break;  
            case 4:  
                cout << "退出查询系统。感谢使用！" << endl;  
                break;  
            default:  
                cout << "无效选择，请重新输入！" << endl;  
                break;  
        }  
    } while (choice != 4);  

    return 0;  
}