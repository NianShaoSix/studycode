#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct Spot {
    string name;//景点名称
    string introduction;//景点简介
    Spot(string n, string i) : name(n), introduction(i) {}
    Spot() {}
};

typedef struct Graph{
    int vexnum,arcnum;//顶点数和边数
    Spot spot[100];//顶点信息
    int arcs[100][100];//邻接矩阵
   
    Graph(int num) {
        vexnum = num;
        arcnum = 0;
        for(int i= 0; i<vexnum; i++){
            for(int  j = 0; j < vexnum; j++){
                arcs[i][j] = (i==j) ? 0 : INT32_MAX;//初始化为无穷大，自身到自身为0
            }
        }
    }
} ;

void creatGraph(Graph *g) {
    cout << "输入景点数：";
    cin >> g ->vexnum;
    puts("");
    cout << "输入道路数";
    cin >> g -> arcnum;
    puts("");

    //输入每个景点的信息
    for(int i = 0;i < g -> vexnum; i++){
        cout << "请输入第" << i+1 << "个景点的名称:";
        cin >> g -> spot[i].name;
        puts("");
        cout << "请输入第" << i+1 << "个景点的简介:";
        cin >> g -> spot[i].introduction;
        puts("");
    }
    //输入每条道路的信息
    for(int i = 0; i < g -> arcnum; i++){
        int v1,v2,w;
        cout << "请输入第" << i+1 << "条道路的起点、终点和长度:";
        cin >> v1 >> v2 >> w;
        puts("");
        g -> arcs[v1][v2] = w;
        g -> arcs[v2][v1] = w;
    }

    //输出邻接矩阵
    cout << "邻接矩阵为：" << endl;
    for(int i = 0; i < g -> vexnum; i++){
        for(int j = 0; j < g -> vexnum; j++){
            cout << g -> arcs[i][j] << " ";
        }
        puts("");
    }
}
//
