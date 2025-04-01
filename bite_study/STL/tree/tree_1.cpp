#include <iostream>
#include <vector> 
using namespace std;

const int N = 1e5+10;
vector<int> edges[N];
int n;
int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int a,b;
        cin >> a >>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    return 0;
}