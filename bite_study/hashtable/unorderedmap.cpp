#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,vector<int>> edges;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }


    return 0;
}