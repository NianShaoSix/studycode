#include <SFML/Graphics.hpp>  
#include <iostream>  
#include <vector>  
#include <limits>  
#include <queue>  
#include <string>  
using namespace std;   
void displayParkMap() {  
    std::cout << "公园平面图:\n";  
    std::cout << "       (0: 中心广场)\n";  
    std::cout << "              | \n";  
    std::cout << "           10 | \n";   
    std::cout << "              | \n";  
    std::cout << "        (1: 游乐园)--(2: 假山)\n";  
    std::cout << "           |    \\    |  /\n";  
    std::cout << "         1 |     \\   | /2\n";  
    std::cout << "           |      \\  |/ \n";  
    std::cout << "        (3: 动物园)--(4: 花园)\n";  
    std::cout << "              \\       /\n";  
    std::cout << "                4    \n";   
    std::cout << std::endl;  
}  

int main() {  
    displayParkMap();  

    // 其余代码（如图的定义、Dijkstra 算法、用户输入等）...  
    
    return 0;  
}
// 边的结构定义  
struct Edge {  
    int destination;  
    int weight;       
};  

// 图的结构定义  
class Graph {  
    int V;                           
    vector<vector<Edge>> adjList;     
    vector<string> nodeNames;          

public:  
    Graph(int v, const vector<string>& names) : V(v), adjList(v), nodeNames(names) {}  

    // 添加边  
    void addEdge(int src, int dest, int weight) {  
        adjList[src].push_back({dest, weight});  
        adjList[dest].push_back({src, weight});  
    }  

    vector<int> dijkstra(int start, int end) {  
        vector<int> distance(V, numeric_limits<int>::max());  
        vector<int> parent(V, -1);  
        vector<bool> visited(V, false);  
        distance[start] = 0;  

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;  
        pq.push({0, start});  

        while (!pq.empty()) {  
            int current = pq.top().second;  
            pq.pop();  

            if (visited[current]) continue;  

            visited[current] = true;  

            for (const auto& edge : adjList[current]) {  
                int next = edge.destination;  
                int weight = edge.weight;  

                if (!visited[next] && distance[current] + weight < distance[next]) {  
                    distance[next] = distance[current] + weight;  
                    parent[next] = current;  
                    pq.push({distance[next], next});  
                }  
            }  
        }  

        vector<int> path;  
        for (int v = end; v != -1; v = parent[v]) {  
            path.push_back(v);  
        }  
        reverse(path.begin(), path.end());  
        return path;  
    }  

    void printNodeNames() {  
        for (size_t i = 0; i < nodeNames.size(); ++i) {  
            cout << "节点 " << i << ": " << nodeNames[i] << endl;  
        }  
    }  
};  

// 展示公园平面图  
void displayParkImage() {  
    sf::RenderWindow window(sf::VideoMode(800, 600), "公园平面图");  

    sf::Texture texture;  
    if (!texture.loadFromFile("park_map.png")) {  
        std::cerr << "Error loading image\n";  
        return;  
    }  
    sf::Sprite sprite(texture);  

    while (window.isOpen()) {  
        sf::Event event;  
        while (window.pollEvent(event)) {  
            if (event.type == sf::Event::Closed)  
                window.close();  
        }  

        window.clear();  
        window.draw(sprite);  
        window.display();  
    }  
}  

int main() {  
    vector<string> nodeNames = {  
        "中心广场",  
        "游乐园",  
        "假山",  
        "动物园",  
        "花园"  
    };  

    Graph g(5, nodeNames);   
    g.addEdge(0, 1, 10); // 中心广场 - 游乐园  
    g.addEdge(0, 2, 5);  // 中心广场 - 假山  
    g.addEdge(1, 2, 2);  // 游乐园 - 假山  
    g.addEdge(1, 3, 1);  // 游乐园 - 动物园  
    g.addEdge(2, 1, 3);  // 假山 - 游乐园  
    g.addEdge(2, 3, 9);  // 假山 - 动物园  
    g.addEdge(2, 4, 2);  // 假山 - 花园  
    g.addEdge(3, 4, 4);  // 动物园 - 花园  
    
    // 展示公园的平面图  
    displayParkImage();  
    cout << "可用的景点:\n";  
    g.printNodeNames();  

    int start, end;  
    cout << "请输入起点景点编号: ";  
    cin >> start;  
    cout << "请输入终点景点编号: ";  
    cin >> end;  

    vector<int> path = g.dijkstra(start, end);  
    if (path.size() > 0 && path[0] == start && path.back() == end) {  
        cout << "从" << nodeNames[start] << "到" << nodeNames[end] << "的最短路径是:";  
        for (int v : path) {  
            cout << " " << nodeNames[v];  
        }  
        cout << endl;  
    } else {  
        cout << "没有找到路径从 " << nodeNames[start] << " 到 " << nodeNames[end] << endl;  
    }  


    return 0;  
}